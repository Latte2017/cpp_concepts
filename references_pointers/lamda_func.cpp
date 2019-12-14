#include<iostream>
#
using namespace std;




int main() {
	int num1 = 10, num2 = 20;
	//auto glambda = [](auto a, auto&& b) { return a < b; };
	auto sum = [](auto num1, auto num2) { return num1 < num2; };
	//cout << sum << endl;

	auto glambda = [](auto a, auto&& b) { return a < b; };
	bool b = glambda(3, 3.14); 
}
