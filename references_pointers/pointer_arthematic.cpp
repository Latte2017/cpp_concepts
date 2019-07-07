#include<iostream>

using namespace std;

int main() {
	int var[2] = { 2,5 };
	int *ptr = var;
	cout << *(++ptr) << endl;
	cout << &ptr << endl;
	int* p;
	p = new int[10*10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			p[i * 10 + j] = (i * 10 + j + 100);
		}
	}
	cout << p[0] << endl;
	delete[] p;
	return 0;

}