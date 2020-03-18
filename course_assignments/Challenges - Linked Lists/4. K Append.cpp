#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    //Constructor 
    node(int d){
        data = d;
        next = NULL;
    }
};
void insertAtTail(node*&head,int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
}
int buildList(node*&head){
    int n;
    cin>>n;
    int a=n;
    while(n--){
        int data;
        cin>>data;
        insertAtTail(head,data);
    }
    return a;
}
void printList(node*head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    printList(head->next);
}
node* checkList(node*head,int k,int n){
    node*last;
    last = head;
    int i=0;
    k = k%n;
    int ok = n-k-1; 
    while(last != NULL && i<ok){
        last = last -> next;
       i++;
    }
    node*second = last->next;
    last->next = NULL;
    return second;
}
int main() {
    int k;
    node* head = NULL;
    int n = buildList(head);
    cin>>k;
    node* temp = checkList(head,k,n);
    printList(temp);
    printList(head);
}

-------------------------------------------------------

#include<iostream>
using namespace std;
class node{
    public:
	int data;
	node *next;
    node(int d){
        data = d;
        next = NULL;
    }
};
void athead(node* &head, int key){
	node *temp = new node(key);
	if(head==NULL){
		head=temp;
		temp->next=NULL;
	}
	else{
		temp->next=head;
		head=temp;
	}	
}
void atend(node* &head, int key){
	if(head==NULL){
        athead(head,key);
        return;
    }
	else {
		node *temp1=head;
		while(temp1->next!=NULL)
			temp1=temp1->next;
		node *temp = new node(key);
		temp1->next=temp;
		temp->next=NULL;
	}
}

void print(node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;	
	}
}
void append(node * &head,int k,int n){
	node *temp=head;
	node *preptr=head;
	node *start=head;
	int count=0;
	while(count<(n-k) && temp!=NULL){
		preptr=temp;
		temp=temp->next;
		count++;
	}
	preptr->next=NULL;
	head=temp;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=start;
}
int main(){
	node *head=NULL;
	int n, k;
	cin>>n;
	int w=n;
	while(n!=0){
		int data;
		cin>>data;
		atend(head,data);
		n--;
	}
	cin>>k;
	if(k==0 || k%w==0)
		print(head);
	else {
	append(head,k%w,w);
	print(head);
	}
}