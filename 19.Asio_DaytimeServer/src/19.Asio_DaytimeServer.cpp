//============================================================================
// Name        : Asio_DaytimeServer.cpp
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
using boost::asio::ip::tcp;

std::string make_daytime_string()
{
  using namespace std; // For time_t, time and ctime;
  time_t now = time(0);
  return ctime(&now);
}

int main() {

	//system_clock::time_point start = system_clock::now();

	boost::asio::io_context io_context;

	tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8200));

	for (;;)
	    {
	      tcp::socket socket(io_context);
	      acceptor.accept(socket);
	      std::string message = make_daytime_string();

	      boost::system::error_code ignored_error;
	            boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
	    }


return 0;
}
