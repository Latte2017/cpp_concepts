#include<iostream>
#include <stack>

using namespace std;

class Node {
public:
	int val = 0;
	Node* left =  NULL;
	Node* right = NULL;
};

class Tree {
public:
	Node* inverseTree(Node* root) {
		Node* tmp = new Node();
		if (root != nullptr) {
			tmp = inverseTree(root->right);
			root->right = inverseTree(root->left);
			root->left = tmp;
		}
		return root;
	}

	Node* inverseTree_2(Node* root) {
		std::stack<Node*> stk;
		stk.push(root);

		while (!stk.empty()) {
			Node* p = stk.top();
			stk.pop();
			if (p) {
				stk.push(p->left);
				stk.push(p->right);
				std::swap(p->left, p->right);
			}
		}
		return root;
	}

	Node* val(Node* in) {
		Node* ret_val = new Node();
		ret_val = in;
		return ret_val;
	}
};

int main() {
	Node* root, * left, * right, *ret_node, *right_right;
	root = new Node();
	left = new Node();
	right = new Node();
	right_right = new Node();
	root->val = 2;
	left->val = 1;
	right->val = 3;
	right_right->val = 5;
	root->left = left;
	root->right = right;
	root->right->right = right_right;
	Tree tr1;
	//ret_node = tr1.val(root);
	ret_node = tr1.inverseTree_2(root);
	cout << ret_node->left->val << ret_node->right->val <<  endl;
	//int x, y = 1, 2;

	return 0;
}