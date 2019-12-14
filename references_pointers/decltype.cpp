/*
decltype Inspects the declared type of entity 
*/

#include<iostream>

using namespace std;

int main() {

	//lambda functions 
	auto f = [](int a, int b) {
		return a * b;
	};

	decltype(f) g = f;
	auto i = f(2, 2);
	auto j = g(3, 3);

	cout << "Value of i is " << i << " value of j is " << j << endl;
}