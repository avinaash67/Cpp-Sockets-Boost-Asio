//============================================================================
// Name        : Asio_AsyncTimer1.cpp
// Author      : Avinaash
// Version     :
// Copyright   : Your copyright notice
// Description : http://think-async.com/Asio/boost_asio_1_16_0/doc/html/boost_asio/tutorial/tuttimer2.html
//============================================================================

#include <iostream>
//#include <chrono>
#include "/usr/local/include/boost/asio.hpp"

using namespace std;
using namespace boost::asio::chrono;

void print(const boost::system::error_code& /*e*/){
	cout << "Inside print() function" << endl;
}
void print2(const boost::system::error_code& /*e*/){
	cout << "Inside print2() function" << endl;
}

int main() {

	system_clock::time_point start = system_clock::now();

	cout << "First line" << endl;
	boost::asio::io_context io;
	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(8));

	cout << "Setting async_wait print()" << endl;
	t.async_wait(&print);


	cout << "Main going to sleep ... " << endl;
	//sleep(2);
	cout << "Main waking up ... " << endl;
	cout << "Setting async_wati(&print2)" << endl;
	t.async_wait(&print2);

	io.run();

	cout <<"After io.run()" << endl;

	auto end = system_clock::now();
	auto diff = duration_cast < std::chrono::seconds > (end - start).count();
	std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;

	return 0;
}
