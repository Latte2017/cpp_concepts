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

	/*
	//Set Difference. Difference of 2 maps but only checks keys
	//Need to use a temporary map f3 and swap elements from f1 and f3 which is constant.
	set_difference(f1.begin(), f1.end(), f2.begin(), f2.end(), inserter(f3,f3.begin()));
	f1.swap(f3);

	//Convert vector to set
	//copy(v1.begin(), v1.end(), inserter(f3, f3.begin()));
	
	*/
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