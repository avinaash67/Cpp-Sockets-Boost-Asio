//============================================================================
// Name        : Vector_STL.cpp
// Author      : Avinaash
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector <int> v1;
	v1.push_back(10);
	v1.push_back(20);
	vector <int> :: iterator itr = v1.begin();

	for(auto &itr : v1){

		cout << itr << endl;

	}


	return 0;
}
