/*
Ordered Sets are implemented using red black tree. 
	
Unordered sets are implemented using hash table.

*/

#include<set>
#include<iostream>
#include <vector>
#include<unordered_set>



using namespace std;

class orderedsetImplementation {
public:
	set<int> insert_elements(set<int> in, int num) {
		// logn time
		in.insert(num);
		return in;
	}

	void delete_element(set<int> &in, int num) {
		//find is logn and delete is 1
		in.erase(num);
	}
};

class unorderedset {
	unordered_set<int> insert(int num) {
		unordered_set<int> ret_set;
		ret_set.insert(num);
		return ret_set;
	}


};

int main() {
	set<int> in;
	in.insert(5);
	in.insert(10);
	in.insert(20);
	set<int>::iterator it = in.find(15);
	if (it != in.end()) {
		cout << "the value at it " << *it << endl;
	}
	else {
		cout << "Element not found " << endl;
	}
	orderedsetImplementation myset;
	myset.delete_element(in, 10);
	set<int>::iterator it2 = in.upper_bound(10);
	set<int>::iterator it3 = in.lower_bound(20);
	cout << *it2 << *it3 << endl;
}