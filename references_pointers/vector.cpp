/*
Vectors are dynamic array. The vectors are reallocated once the capacity is reached.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<time.h>

using namespace std;

int main() {
	vector<int> v1(10);
	vector<int> v2(10, 5); //initialize a vector of size 10 to 5;
	vector<int>::iterator it;
	int myarray[10];
	time_t t;
	srand((unsigned)time(&t));
	for (it = v1.begin(); it != v1.end(); it++) {
		*it = rand() % 50;
	}

	for (int i = 0; i < 10; ++i) {
		myarray[i] = rand() % 70;
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
		
		if ((it - v1.begin()) == 2) {
			v1[5]++; //increment by index
			(*it)++; // increment by iterator
		}
		cout << *it << " index is " << it - v1.begin() << endl;
	}

	v1.push_back(25);
	//lower bound
	//When same value is repeated multiple times. It gives the first instance of the value  a a a a 
	//                                                                                      ^
	it = lower_bound(v1.begin(), v1.end(), 25);
	if (it != v1.end()) {
		cout << *it << endl;
	}


	//upper bound
	//When same value is repeated multiple times. It gives the first instance of the value  a a a a b
	//                                                                                              ^

	it = upper_bound(v1.begin(), v1.end(), 25);
	if (it != v1.end()) {
		cout << *it << endl;
	}

	//Copy array to vector always use range based copy rather than copying individual elements
	v1.assign(begin(myarray), end(myarray));

	for (it = v1.begin(); it != v1.end(); it++) {
		cout << *it << "\t";

	}
}
