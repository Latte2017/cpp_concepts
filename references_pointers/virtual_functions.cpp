#include<iostream>

using namespace std;

class A {
public:
	virtual int func1(int) {
		cout << "Class A called. func1 called." << endl;
		return 0;
	}

	virtual int func2() const {
		cout << "Class A called. func2 called." << endl;
		return 0;
	}
};

class B :public A {
public:
	B() {};
	//override keyword makes compile time checks instead of run time
	int func1(int) override {
		cout << "Class B is called. func1 called" << endl;
		return 0;
	}

};

int main() {
	A* cls1;
	B cls2;

	cls1 = &cls2;
	cls1->func1(3);	
	
}