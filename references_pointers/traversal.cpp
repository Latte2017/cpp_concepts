//Inorder, pre order and post order traversal

#include <list>
#include<vector>
#include <stack>
#include <iostream>

using namespace std;

class Node {
public:
	int val = 0;
	Node* left =  nullptr;
	Node* right = nullptr;
	Node(int x) {
		val = x;
	}
};

class Traversal {
public:
	vector<int> preorder_recursive(Node* root) {
		vector<int> result;
		preorder_recursive_helper(root, result);
		return result;
	}

	void preorder_recursive_helper(Node* root, vector<int>& result) {
		if (root != nullptr) {
			result.push_back(root->val);
			preorder_recursive_helper(root->left, result);
			preorder_recursive_helper(root->right, result);
		}
	}

	vector<int> inorder_iterative(Node* root) {
		vector<int> result;
		stack<Node*> s1;
		Node* n1;
		while(true){
			while (root) {
				s1.push(root);
				root = root->left;
			}
			if(s1.empty()){
				return result;
			}
			n1 = s1.top();
			s1.pop();
			result.push_back(n1->val);
			if (n1->right) {
				root = n1->right;
			}

		}
	}

	vector<int> inorder_recursive(Node* root) {
		vector<int> result;
		inorder_recursive_helper(root, result);
		return result;
	}

	void inorder_recursive_helper(Node* root, vector<int>& result) {
		if (!root) {
			return;
		}
		inorder_recursive_helper(root->left, result);
		result.push_back(root->val);
		inorder_recursive_helper(root->right, result);
	}

	vector<int> preorder_iterative(Node* root){
		vector<int> result;
		stack<Node*> stk;
		stk.push(root);
		while (!stk.empty()) {
			Node* n1 = stk.top();
			result.push_back(n1->val);
			stk.pop();
			if (n1->right != nullptr) {
				stk.push(n1->right);
			}
			if (n1->left != nullptr) {
				stk.push(n1->left);
			}
		}
		return result;

	}
};

/*
	Tree:
					10
			5				12
		1		6		11		13
*/


int main() {
	vector<int> result;
	vector<int>::iterator it;
	Node* root = new Node(10);
	Node* left = new Node(5);
	Node* right = new Node(12);
	Node* left_left = new Node(1);
	Node* left_right = new Node(6);
	Node* right_left = new Node(11);
	Node* right_right = new Node(13);

	root->left = left;
	root->right = right;
	root->left->left = left_left;
	root->left->right = left_right;
	root->right->left = right_left;
	root->right->right = right_right;
	Traversal T1;
	
	result = T1.inorder_iterative(root);
	cout << "Printing inorder iterative" << endl;
	for (it = result.begin(); it != result.end(); it++) {
		cout << *it << endl;
	}
	
	result = T1.inorder_recursive(root);
	cout << "Printing inorder recursive" << endl;
	for (it = result.begin(); it != result.end(); it++) {
		cout << *it << endl;
	}

	result = T1.preorder_recursive(root);
	cout << "Printing preorder recursive" << endl;
	for (it = result.begin(); it != result.end(); it++) {
		cout << *it << endl;
	}
}