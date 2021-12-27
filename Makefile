all: PhotoMagic

PhotoMagic: PhotoMagic.o FibLFSR.o
	g++ PhotoMagic.o FibLFSR.o -o PhotoMagic -lsfml-graphics -lsfml-window -lsfml-system

PhotoMagic.o: PhotoMagic.cpp
	g++ -c PhotoMagic.cpp -Wall -Werror -ansi -pedantic

FibLFSR.o: FibLFSR.cpp FibLFSR.h
	g++ -c FibLFSR.cpp -Wall -Werror -ansi -pedantic

clean:
	rm *.o PhotoMagic

