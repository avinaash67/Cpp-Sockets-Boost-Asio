//============================================================================
// Name        : Async_3.cpp
// Author      : Avinaash
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <string>

using namespace std;
using namespace std::chrono;

string get_data_from_DB(string recv){

	this_thread::sleep_for(seconds(10));

	return recv+"_DB";
}

string get_data_from_FILE(string recv){

	this_thread::sleep_for(seconds(5));

	return recv+"_FILE";
}


int main() {
	cout << "---Hello World---" << endl << endl; // prints !!!Hello World!!!

	system_clock::time_point start = system_clock::now();

	future<string> dbData = async(get_data_from_DB,"data");
	//string dbData = get_data_from_FILE("Data");
	string fileData = get_data_from_FILE("Data");

	//Combine The Data
	//string data = dbData.get() + " :: " + fileData;
	string data = dbData.get() + " :: " + fileData;

	auto end = system_clock::now();

	auto diff = duration_cast < std::chrono::seconds > (end - start).count();
	std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;

	//Printing the combined Data
	cout << "Data = " << data << endl;

	return 0;
}
