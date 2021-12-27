#include "FibLFSR.h"

FibLFSR::FibLFSR(string seed){
	int temp;

	for(int i = 0;i < 16; i++){
		temp = seed[i] - 48;
		regist.push_back(temp);
	}
}

int FibLFSR::step(void){
	int tap1;
	int tap2;
	int tap3;
	tap1 = regist.at(0)^regist.at(2);
	tap2 = regist.at(3)^tap1;
	tap3 = regist.at(5)^tap2;
	regist.erase(regist.begin());
	regist.push_back(tap3);
	return tap3;
	
}

int FibLFSR::generate(int k){
	int temp = 0;
	for(int j = 0; j < k; j++){
		int temp2 = step();
		temp *=2;
		temp += temp2;
	}

	return temp;
}

int FibLFSR::getRegisterSize(){
	return regist.size();
}
int FibLFSR::getBit(int index){
	return regist.at(index);
}

ostream& operator<< (ostream& out, const FibLFSR& fiblfsr){
	for (int i = 0; i < 16; i++){
		cout << fiblfsr.regist.at(i);
	}
	cout << "\n";
	return out;
}

