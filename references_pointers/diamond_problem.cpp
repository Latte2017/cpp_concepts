#include<iostream>

using namespace std;


class A {
	int X;
public:
	void st(int a) {
		X = a;
	}

	void print() {
		cout << X << endl;
	}
};


class B: virtual public A {
public:
	B() {
		st(20);
	}
};

class C : virtual public A {
public:
	C() {
		st(10);
	}

};



class D : public C, public B {
};

int main() {
	D d;
	d.print();
}
