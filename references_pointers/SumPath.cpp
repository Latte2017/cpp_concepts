/*Given a binary tree and a number, return true if the tree has a root-to-leaf path
such that adding up all the values along the path equals the given number. Return false if no such path can be found.
*/

#include<iostream>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x){
		val = x;
	}
};

class Tree {
public:
	bool SumPath(TreeNode* root, int sum) {
		bool left = false;
		bool right = false;
		if (root->val == sum and root->left == nullptr and root->right == nullptr) {
			return true;
		}
		if (root->left)
			left = SumPath(root->left, (sum - root->val));
		if (root->right)
			right = SumPath(root->right, (sum - root->val));
		else
			right = 0;
		if (left == true or right == true)
			return true;
		else
			return false;
	}
};


int main() {
	TreeNode* root, * left, * right, * left_left, * left_left_right;
	root = new TreeNode(100);
	left  = new TreeNode(50);
	right = new TreeNode(200);
	left_left = new TreeNode(25);
	left_left_right = new TreeNode(35);
	root->left = left;
	root->right = right;
	left->left = left_left;
	left_left->right = left_left_right;
	Tree t1;
	cout << "Return value is " << t1.SumPath(root, 210) << endl; 
	return 0;
}
