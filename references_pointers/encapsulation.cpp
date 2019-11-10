/*
To hide data 
*/
#include<iostream>

using namespace std;

class encapsulation {
private:
	int num_coins = 0;
	int value = 0;
public:
	int get_value() {
		return value;
	}
	void set_value(int x) {
		num_coins += 1;
		value += x;
	}
};

int main() {
	int curr_coin, option = 2;
	encapsulation e1;
	while (true){
		cout << "Please enter a option" << endl;
		cin >> option;
		switch (option) {
			
			case 1:
				cout << "value is " << e1.get_value() << endl;
				getchar();
				break;
			case 2:
				cout << "Please enter a coin number" << endl;
				cin >> curr_coin;
				e1.set_value(curr_coin);
				break;
			default:
				cout << "Invalid entry" << endl;
				getchar();
				exit(1);
		}
	}
}