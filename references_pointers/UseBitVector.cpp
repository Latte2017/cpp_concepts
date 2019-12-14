#include <bitset>
#include <iostream>

using namespace std;

int main() {
	bitset<32> bit_vec;

	cout << bit_vec << endl;

	bit_vec[4] = true;

	cout << bit_vec << endl;
}