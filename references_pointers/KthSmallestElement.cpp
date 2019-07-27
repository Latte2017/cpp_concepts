#include<iostream>
#include<stack>
//Find Kth smallest in BST

using namespace std;

class Node {
public:
	int val = 0;
	Node* left = NULL;
	Node* right = NULL;
};

class BinaryTree {
public:
	Node* KthSmallest(Node* root, int k) {
		Node* right = new Node();
		stack<Node*> stk;
		int iter = 0;
		while (root) {
			stk.push(root);
			root = root->left;
		}
		
		while (iter < k and !stk.empty()) {
			root = stk.top();
			stk.pop();
			iter++;
			right = root->right;
			while (right) {
				stk.push(right);
				right = right->left;
			}
		}
		return root;
	}
};

int main() {
	Node* left_left, * left_right, * left, * right, * right_left, * right_right, *root, *ret_node;
	int k = 3;
	left_left = new Node();
	left_right = new Node();
	left = new Node();
	right = new Node();
	right_left = new Node();
	right_right = new Node();
	root = new Node();
	ret_node = new Node();
	root->val = 5;
	left_left->val = 1;
	left_right->val = 3;
	left->val = 2;
	right->val = 7;
	right_left->val = 6;
	right_right->val = 8;
	root->left = left;
	root->right = right;
	left->left = left_left;
	left->right = left_right;
	right->left = right_left;
	right->right = right_right;
	BinaryTree b1;
	ret_node = b1.KthSmallest(root, k);
	cout << "The " << k << " th value is " << ret_node->val << endl;
	return 0;
}