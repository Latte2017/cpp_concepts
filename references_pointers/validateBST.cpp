#include<iostream>

using namespace std;

class TreeNode {
public:
	int val = 0;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
};

class BST {
private:
	bool isvalidBSTHelper(TreeNode* root, long long int min_val, long long int max_val) {
		bool ret_val = false;
		if (root == nullptr) {
			return true;
		}
		if (root->val <= min_val or root->val >= max_val) {
			return false;
		}
		ret_val = isvalidBSTHelper(root->left, min_val, root->val);
		ret_val = ret_val and isvalidBSTHelper(root->right, root->val, max_val);
		return ret_val;
	}
public:
	bool isvalidBST(TreeNode* root) {
		bool ret_val = false;
		ret_val = isvalidBSTHelper(root, LLONG_MIN, LLONG_MAX);
		return ret_val;
	}
};

int main() {
	TreeNode* root, * left, * right, * left_left, * left_right, * left_right_left, * left_right_right;
	bool ret_val = false;
	BST b1;
	root = new TreeNode();
	left = new TreeNode();
	right = new TreeNode();
	left_left = new TreeNode();
	left_right = new TreeNode();
	left_right_left = new TreeNode();
	left_right_right = new TreeNode();
	root->val = 2147483647;
	/*
	root->left = left;
	root->right = right;
	left->left = left_left;
	left->right = left_right;
	left_right->left = left_right_left;
	left_right->right = left_right_right;
	left->val = 50;
	right->val = 200;
	left_left->val = 25;
	left_right->val = 75;
	left_right_left->val = 65;
	left_right_right->val = 85;
	
	*/
	ret_val = b1.isvalidBST(root);
	cout << "The bool value of tree is " << ret_val << endl;
	return 0;
}