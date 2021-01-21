#include<iostream>
using namespace std;

int swap(int& a, int& b){

int temp = 0;

temp = a;
a = b;
b = temp;
cout << a;
}

int main(){

int a = 5;
int b = 10;

cout<<"a = " << a << "b = " << b <<endl;
swap(a,b);
cout<<"a = " << a << "b = " << b <<endl;

}
