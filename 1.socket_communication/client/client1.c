// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <iostream>
#include <sched.h>

using namespace std;

#define PORT 8200
 



int main(int argc, char const *argv[]) 
{ 

	int client_sockfd, read_ret, write_ret, i;
	struct sockaddr_in serv_addr;
	char buffer[255];
	
	//Setting CPU affinity
	const int core_id = 0;
	const pid_t pid = getpid();
	
	cout << "pid client " << pid << endl;
	
	// cpu_set_t: This data set is a bitset where each bit represents a CPU.
	cpu_set_t  cpuset;
	// CPU_ZERO: This macro initializes the CPU set set to be the empty set.
	CPU_ZERO(&cpuset);
	// CPU_SET: This macro adds cpu to the CPU set set.
	CPU_SET(core_id, &cpuset);
	
	/*
	sched_setaffinity: This function installs the cpusetsize bytes long affinity mask pointed 
	to by cpuset for the process or thread with the ID pid. If successful the function returns 
	zero and the scheduler will in future take the affinity information into account.
	*/
	const int set_result = sched_setaffinity(pid, sizeof(cpu_set_t), &cpuset);
	
	if (set_result != 0) {
		printf("sched_setaffinity ERROR: %d \n", set_result);
		exit(1);
	}



	//Creating a client socket
	if((client_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
	
		cout << "Error creating client socket" << endl;			
	}	
 	
	//Setting the sever address details
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	
	//Converting ip address to binary and storing in [&serv_addr.sin_addr]. 
	//The [sin_addr] is an object of  structure [struct  in_addr]
   	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){
		
		cout << "Convertion of ip address to binary has failed" << endl;	
	}
	
	//Connecting clientsocket to server socket
	if(connect(client_sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
	
	cout << "Error connect function call: Error connecting to sever socket" << endl;
	}

	bzero(buffer, 255);
	
	while(1){
		
                //Getting string from user in server side using "stdin"
                bzero(buffer, 255); // clearing the buffer 
                fgets(buffer, 255, stdin);

/*                //Writing into the socket
                
		write_ret = write(client_sockfd, buffer, strlen(buffer));

                if (write_ret < 0){ 
                        cout << "Error writing into client socket" << endl;
                }
		             
*/		

		//Reading from server from socket
		read_ret = read(client_sockfd, buffer, 255);

        	if(read_ret < 0){
                        cout << "Error Reading from socket" << endl;
		}
		
		//printing server data in stdout
                cout << buffer << endl;

                
		/*if ((i = strncmp("close", buffer, 5)) == 0)
                        break;*/
        }

	bzero(buffer, 255);
        cout << "Closing client ..." << endl;

return 0; 
} 

