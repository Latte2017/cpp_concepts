/*Implement a AVL insertion/deletion for a BST
The height difference between any two leaves shouldnt be more than 2
It will satisfy all the properties of BST*/

#include<iostream>

using namespace std;

class Node {
public:
	int val;
	Node* left = nullptr;
	Node* right = nullptr;
	int left_val = 0;
	int right_val = 0;

	Node(int x){
		val = x;
	}
};



class AVL {
public:
	Node* insert(Node* root, int val) {
		
		if (root == nullptr) {
			Node* temp = new Node(val);
			return temp;
		}
		if (val < root->val) {
			root->left = insert(root->left, val);
			root->left_val += 1;
		}
		else if (val > root->val) {
			root->right = insert(root->right, val);
			root->right_val += 1;
		}
		
		//Check if satisfies the AVL properties
		if (root->left_val - root->right_val > 1) {
			//rebalance according to AVL properties
			if (root->left->left_val > 0) {
				//left left case
			}
			else if (root->left->right_val > 0) {
				//left right case
			}
		else if (root->right_val - root->left_val > 0) {
			if (root->right->left_val > 0) {
				//right left case
			}
			else if (root->right->right_val > 0)
		}
			rebalance(root);
		}
		

		return root;
	}

	Node* rebalance(Node* root) {

	}
};

int main() {
	Node* root = new Node(50);
	Node* left = new Node(25);
	root->left = left;
	AVL avl1;
	avl1.insert(root, 75);
	cout << root->right->val << endl;
}