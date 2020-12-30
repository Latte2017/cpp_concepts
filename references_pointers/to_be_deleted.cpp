#include<iostream>

using namespace std;


class Sum {
public:

	int addition(int x, int y, int z) {
		return x + y + z;
	}

	float addition(float x, float y, float z) {
		return x + y + z;
	}

	float addition(float x, float y, float z, float k) {
		return x + y + z + k;
	}
};


class A {
private:
	int x=10, y=11;
public:
	virtual void print() {
		cout << "Base class print is called" << endl;
	}

	void call() {
		cout << "Base class call is called" << endl;
	}

	int sum() {
		return x + y;
	}

	int set(int x, int y) {
		this->x = x;
		this->y = y;
		return 0;
	}
};

class B : public A {
public:
	void print() {
		cout << "Derived class print is called" << endl;
	}

	void call() {
		cout << "Derived class call is called" << endl;
	}
};


int main() {
	int x = 10, y = 12, z = 13;
	float a = 11.11F, b = 12.12F, c = 13.13F, d = 14.14F;
	Sum s1;
	cout << s1.addition(x, y, z) << endl;
	cout << s1.addition(a, b, c) << endl;
	cout << s1.addition(a, b, c, d) << endl;
	
	A* a1;
	B b1;
	a1 = &b1;
	a1->print();
	a1->call();
	//Abstarction
	cout << a1->sum() << endl;
	//encapsulation
	a1->set(x, y);
	cout << a1->sum() << endl;
	return 0;
}