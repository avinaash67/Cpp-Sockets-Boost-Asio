//============================================================================
// Name        : Asio_AsyncTimer3.cpp
// Author      : Avinaash
// Version     :
// Copyright   : Your copyright notice
// Description : http://think-async.com/Asio/boost_asio_1_16_0/doc/html/boost_asio/tutorial/tuttimer4.html
//============================================================================

#include <iostream>
#include "/usr/local/include/boost/asio.hpp"
#include "/usr/local/include/boost/bind.hpp"
using namespace std;
using namespace boost::asio::chrono;

class printer
{
private:
	int count_;
	boost::asio::steady_timer timer_;

public:

	printer(boost::asio::io_context& io)
		: timer_(io, boost::asio::chrono::seconds(1)), count_(0){

		timer_.async_wait(boost::bind(&printer::print, this));

	}
	~printer(){
	    std::cout << "Final count is " << count_ << std::endl;
	  }

	void print(){

		if (count_ < 5){
			timer_.expires_at(timer_.expiry()+ boost::asio::chrono::seconds(1));
			timer_.async_wait(boost::bind(&printer::print, this));  // important line
			cout << count_+1 << " secs" << endl;
			count_++;
		}
		else
			cout << "Timer ended" << endl;

	}

};



int main() {

	system_clock::time_point start = system_clock::now();

	boost::asio::io_context io;
	cout << "boost::asio::io_context io  ---- Created" << endl;
	cout << "Creating an object 'p' for printer class" << endl;
	printer p(io);
	cout << "Constructor of printer class activated for 'p' object" << endl;

	cout << "Calling io.run()" << endl;

	io.run();

	auto end = system_clock::now();
	auto diff = duration_cast < std::chrono::seconds > (end - start).count();
	std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;


	return 0;
}
