#include<iostream>
#include<string>

using namespace std;

int main(){
	char c_arr[] ="Avi"; 
	
	char *a = c_arr;
	
	cout << "Size of char array = " << sizeof(a) << endl;
	cout << "Value inside the char* or var 'a' = " << *a << endl; 
	cout << "Starting address of char* = " << &a << endl;


return 0;


}
