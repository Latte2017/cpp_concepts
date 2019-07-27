#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
};

class BinaryTree {
public:
	int maxDepth(Node* root){
		int left = 0, right = 0;
		if (root->left == nullptr and root->right == nullptr) {
			return 1;
		}
		if (root->right != nullptr) {
			right = maxDepth(root->right);
		}
		if (root->left != nullptr) {
			left = maxDepth(root->left);
		}
		return max(left, right) +1;
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
	/*
	left_right->left = left_right_left;
	left_right->right = left_right_right;
	*/
	BinaryTree bt;
	max_depth = bt.maxDepth(root);
	cout << "Max Depth is " << max_depth << endl;
}