#include<iostream>	
using namespace std;
class node{
	public:
	node *next=NULL;
	node *prev=NULL;
	int data;  
	node(int d){       
	    data=d;    
	}
};
void insert(node* &head, node* &tail, int d){	        
	node*newNode = new node(d);
	if(head==NULL){
	    head = tail = newNode;
	    return;
	}        
	tail->next=newNode;
	newNode->prev = tail;
	tail=newNode;
}
int main() {
    node*head=NULL;
    node*tail=NULL;
    int n;
    cin>>n;
    while(n--){
        int d;
        cin>>d;
        insert(head,tail,d);
    }
    while(tail!=head){
        if(head->data==tail->data){
            head=head->next;
            tail=tail->prev;
        }
        else {
            cout<<"False";
            return 0; 
        }
    }
    cout<<"True";
}