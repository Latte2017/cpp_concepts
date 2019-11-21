

#include<iostream>

using namespace std;

class func_overloading {
public:
	//example of function overloading
	int sum(int x, int y, int z) {
		return x + y + z;
	}
	float sum(float x, float y, float z) {
		return x + y + z;
	}
};

//operator overloading
class Complex {
private:
	float x, y;
public:
	Complex(float a, float b) {
		x = a;
		y = b;
	}
	Complex operator + (Complex const& obj) {
		Complex res(0.0,0.0);
		res.x = x + obj.x;
		res.y = y + obj.y;
		return res;
	}
	void print() {
		cout << "real part is " << x << "imaginary part is " << y << endl;
	}
};