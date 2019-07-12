#include<iostream>

using namespace std;

class linkedList {
private:
	int data;
	linkedList* Next = NULL;
public:
	linkedList(int d) {
		data = d;
	}
	void appendTail(int d) {
		linkedList *end = new linkedList(d);
		linkedList *n = this;
		while (n->Next != NULL) {
			n = n->Next;
		}
		n->Next = end;
	}
	void displaylinkedList() {
		linkedList* ptr;
		ptr = this;
		while (ptr != NULL) {
			cout << ptr->data << endl;
			ptr = ptr->Next;
		}
	}
};




int main() {
	linkedList l1(5);
	l1.appendTail(10);
	l1.displaylinkedList();
}