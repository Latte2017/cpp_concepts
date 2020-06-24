

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


int main() {
	func_overloading f1;
	int output = f1.sum(1, 2, 3);
	float a = 1.1, b = 2.2, c = 3.3;
	float output2 = f1.sum(a,b,c);
	cout << output2 << endl;
	Complex c1(a,b), c2(a,b);
	Complex c3 = c1 + c2;
	c3.print();

}