//Name: Matthew Bedard
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.h"

void transform(sf::Image&, FibLFSR*);

int main(int argc, char* argv[]){

	sf::Image image;
	if(!image.loadFromFile(argv[1]))
		return -1;
	
	sf::Image image2;
	if(!image2.loadFromFile(argv[1]))
		return -1;
	
	sf::Vector2u size = image.getSize();
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Before");
	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "After");

	sf::Texture texture1;
	texture1.loadFromImage(image);
	
	sf::Sprite sprite1;
	sprite1.setTexture(texture1);
	FibLFSR flfsrobj(argv[3]);

	transform(image2, &flfsrobj);

	sf::Texture texture2;
	texture2.loadFromImage(image2);
	
	sf::Sprite sprite2;
	sprite2.setTexture(texture2);

	while(window1.isOpen() && window2.isOpen()){
		sf::Event event;
		while(window1.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window1.close();
		}
		while(window2.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window2.close();
		}

		window1.clear();
		window1.draw(sprite1);
		window1.display();
		window2.clear();
		window2.draw(sprite2);
		window2.display();
	}

 	if(!image2.saveToFile(argv[2]))
		return -1;
	return 0;
}

void transform(sf::Image& pic, FibLFSR* randInt){
	sf::Color p;
	sf::Vector2u size2 = pic.getSize();
	for(unsigned i = 0; i < size2.x; i++){
		for(unsigned j = 0; j < size2.y; j++){
			int temp = randInt->generate(8);
			p = pic.getPixel(i, j);
			p.r = p.r ^ temp;	
			temp = randInt->generate(8);
			p.g = p.g ^ temp;
			temp = randInt->generate(8);
			p.b = p.b ^ temp;
			pic.setPixel(i,j,p);
		}
	}

	


}
