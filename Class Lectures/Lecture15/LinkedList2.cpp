

#include <iostream>
using namespace std;

//class node
class node {
public:
	int data;
	node* right;
	node* down;
	node(int d) {
		data = d;
		right = NULL;
		down = NULL;
	}
};

void insertDown(node* &head, int data) {
	if (head == NULL) {
		head = new node(data);
		return;
	}
	node* temp = head;
	while (temp->down != NULL) {
		temp = temp->down;
	}
	temp->down = new node(data);
	return;
}

node* merge(node* a, node* b) {

	if (a == NULL) {
		return b;
	}
	else if (b == NULL) {
		return a;
	}
	node*c;
	if (a->data <= b->data) {
		c = a;
		c->down = merge(a->down, b);
	}
	else {
		c = b;
		c->down = merge(a, b->down);
	}
	return c;

}

node* flat(node* head) {
	if (head == NULL || head->right == NULL) {
		return head;
	}
	node *c = merge(head, flat(head->right));
	return c;
}

//print the linked list
void print(node *head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->down;
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	node* head = NULL;
	insertDown(head, 3);
	insertDown(head, 9);
	insertDown(head, 10);
	insertDown(head, 11);
	insertDown(head->right, 9);
	insertDown(head->right, 11);
	insertDown(head->right, 16);
	insertDown(head->right->right, 5);
	insertDown(head->right->right, 6);
	insertDown(head->right->right, 7);
	head = flat(head);
	print(head);



	return 0;
}











