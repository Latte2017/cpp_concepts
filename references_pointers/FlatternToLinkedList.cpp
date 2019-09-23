/*

[1,2,6,3,4,5,7,null,null,null,9]
Expected
[1,null,2,null,3,null,4,null,9,null,6,null,5,null,7]

Flattern a binary tree
*/

//114. Flatten Binary Tree to Linked List

#include<iostream>
#include <stack>

using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
     int val = 0;
      TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Tree {
public:
	void flatten(TreeNode* root) {
		/*
		        1. flatten left subtree         
				2. find left subtree's tail         
				3. set root's left to None, root's right to root'left, tail's right to root.right        
				4. flatten the original right subtree 
		
		*/
		TreeNode* right = new TreeNode(0);
		TreeNode* tail = new TreeNode(0);
		if (root == nullptr) {
			return;
		}
		right = root->right;
		if (root->left) {
			flatten(root->left);
			tail = root->left;
			while (tail->right) {
				tail = tail->right;
			}
			root->right = root->left;
			root->left = nullptr;
			tail->right = right;
		}
		flatten(right);
		return;
	}

	// O(nlogn) 
	//Go down to the right most node and point to root right node and repeat
	void flatten_v2(TreeNode* root) {
		TreeNode* t1 = new TreeNode(0);
		while (root != nullptr) {
			if (root->left and root->right) {
				t1 = root->left;
				while (t1->right) {
					t1 = t1->right;
				}
				t1->right = root->right;
			}
			if (root->left) {
				root->right = root->left;
				root->left = nullptr;
				root = root->right;
			}
		}
	}

	void printNode(TreeNode* root) {
		while (root != nullptr) {
			cout << root->val << "-> ";
			root = root->right;
		}
		cout << " NULL" << endl;
		return;
	}
};




int main() {
	TreeNode* root, * left, * right, * ret_node, * right_right, *left_left;
	root = new TreeNode(2);
	left = new TreeNode(1);
	right = new TreeNode(3);
	right_right = new TreeNode(5);
	left_left = new TreeNode(0);
	root->left = left;
	root->right = right;
	right->right = right_right;
	left->left = left_left;
	Tree t1;
	t1.flatten(root);
	t1.printNode(root);
	return 0;
}