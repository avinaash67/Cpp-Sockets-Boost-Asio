#include<iostream>

using namespace std;

//#define M 2
//#define N 2

int main(){
	
	
	int temp = 0;
	int M = 0;
	int N = 0;
	 
	cout << "Enter the number of rows" << endl;
	cin >> temp;
	M = int(temp);
	cout << "Enter the number of cols" << endl;
	cin >> temp;
	N = int(temp);
	
	int *m_arr = new int[M*N];	
	
	cout << "matrix of size " << M << " * " << N << " declared" << endl ;
	cout << "total memory allocated is = " << sizeof(m_arr+1); 
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			cin >> temp;
			*(m_arr + i*N + j) = int(temp);
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			std::cout << *(m_arr + i*N + j) << " ";    // or (A + i*N)[j])

		std::cout << std::endl;
	}
	

	
	

return 0;
}
