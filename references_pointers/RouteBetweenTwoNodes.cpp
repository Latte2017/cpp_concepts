//4.2 Given a directed graph. Find if a route exists betwenn two nodes

#include<iostream>

using namespace std;

class Node {
private:
	int val;
	Node* next;
public:
	Node(int x) {
		val = x;
		next = NULL;

	}
};

class Graph {

};