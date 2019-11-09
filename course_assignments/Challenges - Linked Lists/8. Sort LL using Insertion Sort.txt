#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node *next;
    node(int d) {
        data=d;
        next=NULL;
    }
};
void insertAtTail(node* &head, int data) {
    if(head==NULL) {
        head=new node(data);
        return;
    }
    node *temp = head;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = new node(data);
    return;
}
void buildlist(node* &head) {
    int n;
    cin>>n;
    int data;
    while(n>0) {
        cin>>data;
        insertAtTail(head,data);
        n--;
    }
}
void segregate(node* &head) {
    node *current = head;
    node *insert = head;
    current = head->next;
    while(current != NULL) {
        insert = head;
        while(insert != current) {
            if(insert->data >= current->data) {
                int temp = current->data;
                current->data = insert->data;
                insert->data = temp;
            }
            else
                insert = insert->next;
        }
        current = current->next;
    }
}
void print(node *head) {
    while(head!=NULL) {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main() {
    node *head=NULL;
    buildlist(head);
    segregate(head);
    print(head);
	return 0;
}