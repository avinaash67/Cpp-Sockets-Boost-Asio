//============================================================================
// Name        : Asio_AsyncTimer2.cpp
// Author      : Avinaash
// Version     :
// Copyright   : Your copyright notice
// Description : http://think-async.com/Asio/boost_asio_1_16_0/doc/html/boost_asio/tutorial/tuttimer3.html
//============================================================================

#include <iostream>
#include "/usr/local/include/boost/asio.hpp"
#include "/usr/local/include/boost/bind.hpp"
using namespace std;
using namespace boost::asio::chrono;

void print(const boost::system::error_code&, boost::asio::steady_timer *t, int *count){

	  if (*count < 5)
	  {
	    std::cout << "counter =" << *count << endl;
	    ++(*count);

	    t-> expires_at(t->expiry() + boost::asio::chrono::seconds(1));

	    t-> async_wait(boost::bind(print, boost::asio::placeholders::error, t, count));

	  }

}

int main() {

	system_clock::time_point start = system_clock::now();

	int count =0;

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	boost::asio::io_context io;
	boost::asio::steady_timer t(io, seconds(1));

	t.async_wait(boost::bind(print, boost::asio::placeholders::error, &t, &count));
	io.run();

	cout << "Main ended" << endl;

	auto end = system_clock::now();
	auto diff = duration_cast < std::chrono::seconds > (end - start).count();
	std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;

	return 0;
}
