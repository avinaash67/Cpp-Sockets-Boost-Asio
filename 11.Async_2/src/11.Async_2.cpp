//============================================================================
// Name        : Async_2.cpp
// Author      : Avinaash
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <future>
#include <vector>
using namespace std;

int called_from_async(int m){
	return 2*m;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	vector <future <int>> futures;

	futures.push_back(async(called_from_async, 1));
	futures.push_back(async(called_from_async, 2));
	futures.push_back(async([](int m){return 2*m;}, 5));
	for(future<int> &f : futures){

		cout << f.get() <<endl;
	}

	return 0;
}
