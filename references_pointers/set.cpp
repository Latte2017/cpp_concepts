/*
Ordered Sets are implemented using red black tree. 
	
Unordered sets are implemented using hash table.

*/

#include<set>
#include<iostream>



using namespace std;

class setImplementation {
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

int main() {
	set<int> in;
	in.insert(5);
	in.insert(10);
	set<int>::iterator it = in.find(15);
	if (it != in.end()) {
		cout << "the value at it " << *it << endl;
	}
	else {
		cout << "Element not found " << endl;
	}
	setImplementation myset;
	myset.delete_element(in, 10);

}