#include<iostream>
#include <algorithm>

using namespace std;

class Node {
public:
	int val = 0;
	Node* left = NULL;
	Node* right = NULL;
	Node(int x) {
		val = x;
	}
};

class BinaryTree {
private: 
	int Height(Node* root) {
		if (root == nullptr) {
			return 0;
		}
		return max(Height(root->left), Height(root->right)) + 1;
	}
public:
	bool isBalanced(Node* root) {
		int left_height = 0, right_height = 0;
		if (root->left == nullptr && root->right == nullptr) {
			return true;
		}
		if (root->left == nullptr && Height(root->right) >= 2) {
			return false;
		}
		else if (root->right == nullptr && Height(root->left) >= 2) {
			return false;
		}
		else if (abs(Height(root->left) - Height(root->right)) >= 2) {
			return false;
		}
		return true;
	}
};


int main() {
	BinaryTree bt;
	bool ret_val = false;
	Node* root, * left, * right, * left_left, * left_left_right;
	root = new Node(100);
	left = new Node(50);
	left_left = new Node(25);
	left_left_right = new Node(30);
	right = new Node(200);
	root->left = left;
	root->right = right;
	left->left = left_left;
	left_left->right = left_left_right;
	ret_val = bt.isBalanced(root);

	cout << "Ret Val is " << ret_val << endl;

}