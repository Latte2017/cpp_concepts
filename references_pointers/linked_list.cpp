#include<iostream>

using namespace std;

class Node {
public:
	int data=0;
	Node* Next = NULL;
};

class LinkedList {
public:
	void createList(Node** head_ref, int d) {
		Node* new_node = new Node();
		new_node->data = d;
		new_node->Next = (*head_ref);
		(*head_ref) = new_node;
		return;
	}
	void deleteList(Node** head, int d) {
		Node* n1 = *head, *n2;
		if (n1->Next != nullptr)
			n2 = (*head)->Next->Next;
		else
			n2 = nullptr;
		if (n2 == nullptr) {
			if (n1->data == d) {
				*head = n1->Next;
				free(n1);
			}
			else if (n1->Next->data == d) {
				(*head)->Next = NULL;
				return;
			}
			else
				return;
		}
		while (n2 != nullptr) {
			if (n1->data == d) {
				(*head) = n1->Next;
				free(n1);
				return;
			}
			else if (n1->Next->data == d) {
				n1->Next->data = n2->data;
				n1->Next->Next = n2->Next;
				free(n2);
				return;
			}
			n1 = n2;
			n2 = n2->Next;
		}
		return;
	}


	void appendToList(Node** head, int d) {
		Node* l1 = new Node();
		l1->data = d;
		Node* tmp = *head;
		while (tmp->Next != nullptr) {
			tmp = tmp->Next;
		}
		tmp->Next = l1;
		return;
	}

	void displayList(Node** head) {
		Node* tmp = *head;
		while (tmp != nullptr) {
			cout << " " << tmp->data << " -> ";
			tmp = tmp->Next;
		}
		cout << "\n";
	}
	
};


int main() {
	Node* head = NULL;
	LinkedList* l1 =  NULL;
	l1->createList(&head, 5);
	l1->appendToList(&head, 10);
	l1->appendToList(&head, 15);
	//l1->displayList(&head);
	l1->deleteList(&head, 10);
	l1->deleteList(&head, 5);
	l1->displayList(&head);

}