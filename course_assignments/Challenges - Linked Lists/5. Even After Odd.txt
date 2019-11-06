#include<iostream>
using namespace std;
class Node {
public:
	int data; 
	Node *next; 
	Node(int d) {
		data = d;
		next = NULL;
	}
}; 
void segregateEvenOdd(Node* &head) {
	Node *end = head; 
	Node *prev = NULL; 
	Node *curr = head; 

	while (end->next != NULL){
		end = end->next;
	}
	Node *new_end = end;
	while (curr->data %2 == 0 && curr != end) {
		new_end->next = curr; 
		curr = curr->next; 
		new_end->next->next = NULL; 
		new_end = new_end->next; 
	} 
	if (curr->data%2 != 0) {
		head = curr;
		while (curr != end) {
			if ( (curr->data)%2 != 0 ) {
				prev = curr; 
				curr = curr->next; 
			} 
			else {
				prev->next = curr->next; 
				curr->next = NULL;
				new_end->next = curr;
				new_end = curr;
				curr = prev->next; 
			} 
		} 
	}
	else {
		prev = curr;
	}
	if (new_end!=end && (end->data)%2 == 0) {
		prev->next = end->next; 
		end->next = NULL; 
		new_end->next = end; 
	} 
	return; 
} 
void insertATHead(Node *&head, int data) {
	Node *new_node = new Node(data);
	new_node->next = head;
	head = new_node;
}
void insertAtTail(Node *&head, int data) {
	if(head == NULL) {
		insertATHead(head, data);
		return;
	}
	Node *temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	Node *new_node = new Node(data);
	temp->next = new_node;
	return;
} 
void printList(Node *node) {
	while (node!=NULL) {
		cout<<node->data<<" "; 
		node = node->next; 
	}
	cout<<endl;
} 

int main() {
	Node* head = NULL;
	int n;
	cin>>n;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		insertAtTail(head,x);
	}
	segregateEvenOdd(head); 
	printList(head); 
	return 0; 
}