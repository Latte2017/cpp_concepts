/*
Template programming

Templates are used for generic programming. We can pass in int or char or even define our own class type

*/

#include<iostream>

using namespace std;

template<class T>

//Template function 
T GetMax(T obj1, T obj2) {
	if (obj1 > obj2) {
		return obj1;
	}
	else {
		return obj2;
	}
}


//Class Template
template<class T>

class TemplateClass {
private:
	T a, b;
public:
	TemplateClass(T a, T b) {
		this->a = a;
		this->b = b;
	}

	bool IsGreater() {
		return a > b;
	}

};


int main() {
	
	int a1 = 5, a2 = 10;
	float a3 = 4.0, a4 = 5.0;

	// Test template function
	int res = GetMax(a1, a2);
	float res1 = GetMax(a3, a4);
	cout << "Int result is " << res << endl;
	cout << "Float result is " << res1 << endl;

	//Test template class
	TemplateClass<int> t1(a1,a2) ;
	cout << t1.IsGreater() << endl;


}



