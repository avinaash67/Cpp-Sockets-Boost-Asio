//============================================================================
// Name        : Map_STL.cpp
// Author      : Avinaash
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	map<int, int> mp;

	mp[1] = 100;
	mp[2] = 200;


	for(auto itr = mp.begin(); itr != mp.end(); itr++){

		cout << itr->first << "--->" << itr->second << endl;
	}



	return 0;
}
