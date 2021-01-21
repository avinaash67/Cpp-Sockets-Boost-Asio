#include<iostream>

using namespace std;

class test_class1{

public:
	int a;
	char b;
	char c;
void print_addr(){

	cout << "address of a = " << this << endl;
	//cout << "address of b = " << this << endl;
	//cout << "address of c = " << this  << endl;
}

};



int main(){

	//int *a = (int*)malloc(sizeof(int);

	test_class1 obj1;
	int c;
	
	void *vp = (void*) &c; 
	
	cout << "Size of the void pointer *vp = " << sizeof(vp) << endl; 
	//cout << "Size of a charachter = " << sizeof(char) << endl;
	//cout << "Size of a charachter = " << sizeof(int) << endl;
	cout << "Size of the class = "  << sizeof(obj1) << endl;	
	cout << "address of obj1 = " << &obj1 << endl;
 	
   	obj1.print_addr();
return 0;
}
