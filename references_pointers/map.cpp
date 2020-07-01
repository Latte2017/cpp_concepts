/*
Associative Containers
Map: Internal implementation is BST. Doesnt invalidate iterators. 
unordered map: hash table. If map resizes it invalidates iterators but otherwise it doesnt.
*/

#include<map>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	map<char, int> f1, f2, f3;
	string mystring = "aabbccd";
	string mystring1 = "abcd";
	vector<int> v1 = { 1,2,3,4,5 };
	for (auto c : mystring) {
		f1[c]++;
	}
	for (auto c : mystring1) {
		f2[c]++;
	}
	
	//Accessing elements. O(1) time
	for (auto it = f1.begin(); it != f1.end(); ++it) {
		cout << "key is " << it->first << " Value is " << it->second << endl;
	}

	//Set Difference. Difference of 2 maps but only checks keys
	//Need to use a temporary map f3 and swap elements from f1 and f3 which is constant.
	set_difference(f1.begin(), f1.end(), f2.begin(), f2.end(), inserter(f3,f3.begin()));
	f1.swap(f3);

	
	//Difference is [] insets if not present but at throws an error
	cout << f1['a'] << endl;
	cout << f1.at('a') << endl;

	
	//Find and erase a key and value
	f1.erase(f1.find('a'));
	//find(f1.begin(), f1.end(), 'a');

	
	//Lower bound. First iterator of a.
	//cout << lower_bound(f1.begin(), f1.end(), 'a')->first << endl;
	cout << (f1.lower_bound('a')->first) << endl;
	
	//Upper bound is next larger element.
	//If it doesnt exist return end
	cout << (f1.upper_bound('a'))->first << endl;
	
}
