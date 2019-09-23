#include<iostream>
#include<array>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int x) {
		val = x;
	}
};

class BST {
public:
	Node* SortedArrayToBST(int arr[], int begin, int end) {
		if (begin > end) {
			return nullptr;
		}
		int mid = (begin + end) / 2;
		Node* root = new Node(arr[mid]);
		Node* left = SortedArrayToBST(arr, begin, mid-1);
		root->left = left;
		Node* right = SortedArrayToBST(arr, mid+1, end);
		root->right = right;
		return root;
	}

	void printInOrder(Node* root) {
		if (root == nullptr)
			return;
		printInOrder(root->left);
		cout << root->val << endl;
		printInOrder(root->right);
		
	}
};

int main() {
	int arr[4];
	BST b1;
	Node* ret_node = new Node(0);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		arr[i] = unsigned int(i+1);
	}
	if (sizeof(arr) / sizeof(int) % 2 == 0) {
		ret_node = b1.SortedArrayToBST(arr, 0, sizeof(arr) / sizeof(int)-1);
	}
	else
	{
		ret_node = b1.SortedArrayToBST(arr, 0, sizeof(arr) / sizeof(int));
	}
	b1.printInOrder(ret_node);
	return 0;
}