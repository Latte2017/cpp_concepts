/*
https://stackoverflow.com/questions/2253168/dynamic-cast-and-static-cast-in-c
*/

#include<iostream>

using namespace std;


//Static cast

class B {};
class D : public B {};
class X {};


//dynamic cast
class Base {
public:
	virtual void print() {
		cout << "Base class print called" << endl;
	}
};

class Derived1 : public Base {
public:
	void print() {
		cout << "Derived1 class print called" << endl;
	}
};

class Derived2 : public Base {
public:
	void print() {
		cout << "Derived2 print called" << endl;
	}
};



int main()
{
	//Static cast
	D* d = new D;
	B* b1 = new B;
	B* b = static_cast<B*>(d); // this works type case pointer of type d to type B
	D* d1 = static_cast<D*>(b1);
	//X* x = static_cast<X*>(d); // ERROR - Won't compile type case pointer of type d to X

	//dynamic cast
	Base* dynamic_b1 = new Base;
	Derived1* dynamic_d1 = new Derived1;
	Derived2* dynamic_d2 = new Derived2;

	Base* dynamic_b2 = dynamic_cast<Base*>(dynamic_d1);
	Derived2* dynamic_d3 = dynamic_cast<Derived2*>(dynamic_b2); // dynamic_b2 is a base pointer pointing to D1 so it cannot be cast to D2

	if (dynamic_d3 == nullptr) {
		cout << "NULL ptr" << endl;
	}
	return 0;
}