/*
https://stackoverflow.com/questions/274626/what-is-object-slicing#274636
*/

#include<iostream>

using namespace std;

class A {
public:
	int foo = 10;
	A() {
		cout << "Class A called" << endl;
	};
	
};

class B: public A{
public:
	int bar = 30;
	B() {
		cout << "Class B called" << endl;
	}
};


int main() {
	B b;
	A a = b; //bar is lost to A
	B b1;
	B b2;
	A& a_ref = b2;
	a_ref = b1;
}
