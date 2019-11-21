/*
Vectors are dynamic array with a capacity of 1.6 times. The vectors are reallocated once the capacity is reached.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<time.h>

using namespace std;

int main() {
	vector<int> v1(10);
	vector<int>::iterator it;
	time_t t;
	srand((unsigned)time(&t));
	for (it = v1.begin(); it != v1.end(); it++) {
		*it = rand() % 50;
	}
	sort(v1.begin(), v1.end());
	bool present = binary_search(v1.begin(), v1.end(), 3);
	for (it = v1.begin(); it != v1.end(); it++) {
		cout << *it << endl;

	}
	v1.push_back(25);
	cout << "\n Sort in reverse order \n" << endl;
	sort(v1.rbegin(), v1.rend());
	present = binary_search(v1.begin(), v1.end(), 3);
	for (it = v1.begin(); it != v1.end(); it++) {
		cout << *it << endl;

	}
}
