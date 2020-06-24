/*
Copy Constructor
*/

#include<iostream>

using namespace std;

class Print {
public:
	int val = 0;
	Print(int val ){
		this->val = val;
	};
	Print(const Print& t) {
		cout << "Copy Constructor called" << endl;
		this->val = t.val;
	}
	Print& operator = (const Print & t){
		cout << "Assignment operator called" << endl;
		return *this;
	}
};

int main() {
	Print P1(10), P2(20);
	P2 = P1;
	cout << "P2's val is " << P2.val << endl;
	Print P3 = P1;
	cout << "P3s val is " << P3.val << endl;
}