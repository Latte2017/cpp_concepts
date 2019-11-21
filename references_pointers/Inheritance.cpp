/*
Inherits the properties of base class
*/

#include<iostream>

using namespace std;

class base {
private:
	int x = 0;
	int y = 0;
public:
	int sum(int x, int y){
		return (x + y);
	}
};

class classA: public base {

};

int main() {
	classA obj;
	cout << obj.sum(5, 4) << endl;
}