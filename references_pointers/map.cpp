/*
Map: Internal implementation is BST 
unordered map: hash table
*/

#include<map>
#include<string>
#include<iostream>

using namespace std;

int main() {
	map<char, int> f1;
	string mystring = "srivatsa";
	for (auto c : mystring) {
		f1[c]++;
	}
	cout << f1['v'] << endl;
	cout << f1.at('v') << endl;
}
