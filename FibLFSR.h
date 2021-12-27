#ifndef FIBLSFR_H
#define FIBLSFR_H
#include <iostream>
#include <vector>
#include <string>

using namespace std; 
class FibLFSR {
	public:
		FibLFSR(string seed);
		int step();
		int generate(int k);
		int getRegisterSize(); //FOR TESTING PURPOSES
		int getBit(int index); //FOR TESTING PURPOSES 
		friend ostream& operator<<(ostream& out, const FibLFSR& fiblfsr);
	private:
		vector <int> regist;
};

#endif 
