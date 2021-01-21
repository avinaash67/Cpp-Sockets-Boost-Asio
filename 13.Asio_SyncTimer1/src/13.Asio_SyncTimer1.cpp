//============================================================================
// Name        : Asio_SyncTimer1.cpp
// Author      : Avinaash
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include <chrono>
#include "/usr/local/include/boost/asio.hpp"

using namespace std;
using namespace boost::asio;
using namespace boost::asio::chrono;

int main() {

	system_clock::time_point start = system_clock::now();

	cout << "Line 1 checking" << endl;
	io_context  io;
	steady_timer t(io, seconds(8));

	cout << "Main going to sleep ... " << endl;
	sleep(3);
	cout << "Main waking up ... " << endl;

	t.wait();

	cout << "After t.wait()" << endl;

	auto end = system_clock::now();
	auto diff = duration_cast < std::chrono::seconds > (end - start).count();
	std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;

	return 0;
}
