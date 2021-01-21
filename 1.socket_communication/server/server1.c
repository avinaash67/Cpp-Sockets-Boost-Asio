// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 

//user headers
#include <iostream>
using namespace std;

#define PORT 8200
//end user headers

int main(int argc, char *argv[]){

	int server_sockfd, acceptor_sockfd, read_ret, write_ret, i;
	char buffer[255];
	struct sockaddr_in serv_addr;

	//Creating the Server socket
	if((server_sockfd = socket(AF_INET, SOCK_STREAM, 0))==0){

		cout << "Socket Creation Error" << endl;
		exit(EXIT_FAILURE);
	} 
	serv_addr.sin_family = AF_INET;;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);
	
	//Binding the socket to the ipaddress and the port number
	if((bind(server_sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)))<0){
		
		cout <<"binding failed" << endl;
	}	
	
	//Setting the Socket to Listen to connections
	if(listen(server_sockfd,3)<0){
	
	cout << "listen failed" << endl;
	}

	//Accepting Client connection
	if((acceptor_sockfd = accept(server_sockfd, (struct sockaddr*)&serv_addr, (socklen_t*)&serv_addr))<0){
	
		cout<<"Error accepting connection from client" << endl;
	} 

	//Reading the message sent from client	
	while(1){
	
/*		read_ret = read(acceptor_sockfd, buffer, 255);
		
		if(read_ret < 0)
			cout << "Error Reading from socket" << endl;
		
		cout << buffer << endl;
*/		
		//Getting string from user in server side using "stdin"
		//bzero(buffer, 255); // clearing the buffer 
		fgets(buffer, 255, stdin); 
		
		//Writing into the socket
		write_ret = write(acceptor_sockfd, buffer, strlen(buffer));
		
		if (write_ret < 0){
			cout << "Error writing into socket" << endl;
		}	
		
		if ((i = strncmp("close", buffer, 5)) == 0)
			break;  
	}	

	bzero(buffer, 255);
	cout << "Closing Server ..." << endl;
			
return 0; 

} 

