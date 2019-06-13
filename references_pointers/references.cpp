#include<iostream>

using namespace std;

int main() {
	//References
	int a = 10;
	int& b = a;
	const int& c = b;
	a = a + 1;
	cout << a << "\t" << c << endl;
	const int& bb = a;
	cout << bb << endl;

	//Pointers
	int* e1 = &a;
	*e1 = 0;
	cout << *e1 << a <<  endl;
	int i = 42;
	int* p1 = &i;
	*p1 = *p1 * *p1;
	cout << *p1 << endl;

	//pointers to pointer
	int ival = 1024;
	int* pi = &ival;
	int** ppi = &pi;
	cout << "pointer to pointer is " << *pi <<  "\t" << **ppi << endl;

	//references to pointers
	int*& ref3 = pi;
	cout << *(*&ref3) << endl; //dereferencing a reference to pointer's value
	
}