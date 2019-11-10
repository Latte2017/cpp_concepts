/*
Hide the implementation details
*/

#include<iostream>

using namespace std;

class encapsulate {
private:
	int x, y;
	int ret_sum() {
		return x + y;
	}
public:
	void set_num(const int &a, const int &b) {
		x = a;
		y = b;
	}
	int get_sum() {
		return ret_sum();
	}
};

int main() {
	int a =0, b =0;
	int option = 1;
	encapsulate e1;
	do {
		cout << "enter the option" << endl;
		cin >> option;
		if (option == 1) {
			cout << "enters 2 values " << endl;
			cin >> a >> b;
			e1.set_num(a, b);
		}
		else if (option == 2) {
			cout << e1.get_sum() << endl;
		}
	}while(option == 1 || option == 2);
}