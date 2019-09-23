#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Node {
public:
	int val = 0;
	Node* left;
	Node* right;
};

class Tree {
public:
	int minHeightTree(Node* root){
		int left_ht = 0, right_ht = 0;
		if (root == nullptr) {
			return 0;
		}
		right_ht = minHeightTree(root->right);
		left_ht = minHeightTree(root->left);
		return (left_ht, right_ht) + 1;
	}
};

int main() {
	Node* root, * left, * right, * left_left, * left_right, * left_right_left, * left_right_right;
	int max_depth = 0;
	root = new Node();
	left = new Node();
	right = new Node();
	left_left = new Node();
	left_right = new Node();
	left_right_left = new Node();
	left_right_right = new Node();
	root->left = left;
	root->right = right;
	left->left = left_left;
	left->right = left_right;
	
	left_right->left = left_right_left;
	left_right->right = left_right_right;
	
	int min_ht = 0;
	Tree t1;
	min_ht = t1.minHeightTree(root);
	cout << "minimum height is " << min_ht << endl;
	return 0;
}

