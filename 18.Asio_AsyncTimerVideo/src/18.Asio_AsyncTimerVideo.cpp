//============================================================================
// Name        : Asio_AsyncTimerVideo.cpp
// Author      : Avinaash
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <thread>
#include "/usr/local/include/boost/asio.hpp"
//#include "/usr/local/include/boost/thread/thread.hpp"
#include "/usr/local/include/boost/bind.hpp"

using namespace std;
using namespace boost::asio::chrono;



void func_call_back(const boost::system::error_code& e, string name){

	cout << name << " going to sleep" <<endl;
	std::this_thread::sleep_for(std::chrono::seconds(5));
	cout << name << " waking up" <<endl;
}

int main() {

	system_clock::time_point start = system_clock::now();

	cout << " Line 1 ---- > !!!Hello World!!!" << endl; // prints !!!Hello World!!!

	boost::asio::io_context io1;


	boost::asio::strand <boost::asio::io_context::executor_type> strand(boost::asio::make_strand(io1));


	boost::asio::steady_timer t(io1, boost::asio::chrono::seconds(2));



	t.async_wait(boost::asio::bind_executor(strand, boost::bind(&func_call_back, boost::asio::placeholders::error, "Timer1")));
	t.async_wait(boost::asio::bind_executor(strand, boost::bind(&func_call_back, boost::asio::placeholders::error, "Timer2")));

	std::thread thread1([&](){io1.run();});
	std::thread thread2([&](){io1.run();});

	thread1.join();
	thread2.join();

	auto end = system_clock::now();
	auto diff = duration_cast < std::chrono::seconds > (end - start).count();
	std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;

	cout << "Threads have joined";
	return 0;
}
