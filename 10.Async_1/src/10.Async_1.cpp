//============================================================================
// Name        : Async_1.cpp
// Author      : Avinaash
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <future>
#include <unistd.h>
using namespace std;

void called_from_async(){
	while(1){
	cout << "Called from Async. I am a callback function" << endl;
	sleep(1);
	}
}

int main() {
	cout << "-----Hello World----" << endl; // prints !!!Hello World!!!

	future<void> result(async(called_from_async));

	cout << "Message from Main" << endl;

	return 0;
}
