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

struct Details {};


class X
{
public:
	int id;
	int subId;
};

struct Comparator
{
	using is_transparent = std::true_type;

	// standard comparison (between two instances of X)
	bool operator()(const X& lhs, const X& rhs) const { return lhs.id < rhs.id; }

	// comparison via id (compares X with integer)
	bool operator()(const X& lhs, int rhs) const { return lhs.id < rhs; }
	bool operator()(int lhs, const X& rhs) const { return lhs < rhs.id; }

};









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


	std::map<X, Details, Comparator> detailsMap = {
		{ X{1, 2}, Details{} },
		{ X{3, 4}, Details{} },
		{ X{5, 6}, Details{} }
	};

	// it1 and it2 point to the same element.
	auto it1 = detailsMap.find(X{ 1, 2 });
	auto it2 = detailsMap.find(1);

	//std::cout << detailsMap.size() << std::endl;
	//std::cout << std::boolalpha << (it1 == detailsMap.end()) << std::endl; // false
	//std::cout << std::boolalpha << (it1 == it2) << std::endl; // true



}
