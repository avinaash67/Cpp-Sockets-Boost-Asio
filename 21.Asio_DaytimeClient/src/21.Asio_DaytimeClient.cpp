//============================================================================
// Name        : Asio_DaytimeClient.cpp
// Author      : Avinaash
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "/usr/local/include/boost/array.hpp"
#include "/usr/local/include/boost/asio.hpp"
#include "/usr/local/include/boost/asio/impl/connect.hpp"

using boost::asio::ip::tcp;

using namespace std;

int main(int argc, char* argv[]) {
	try{
		if (argc != 2){
		  std::cerr << "Usage: client <host>" << std::endl;
		  return 1;
			}
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	  }

	boost::asio::io_context io_context;

	    tcp::resolver resolver(io_context);
	    tcp::resolver::results_type endpoints =
	      resolver.resolve(argv[1], "daytime");

	    tcp::socket socket(io_context);
	    boost::asio::connect(socket, endpoints);

	for (;;){
	      boost::array<char, 128> buf;
	      boost::system::error_code error;

	      size_t len = socket.read_some(boost::asio::buffer(buf), error);
	    }

	return 0;
}
