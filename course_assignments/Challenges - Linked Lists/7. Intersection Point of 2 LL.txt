#include<iostream>
#include<cmath>
using namespace std;
class node {
    public:
    int data;
    node*next;
    node(int d){
        data=d;
        next=NULL;
    }
};
void insert(node*&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new node(d);
    return;
}
void print(node*head){
    if(head==NULL){
        return;
    }
    while(head->next!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data<<endl;
    return;
}
int interData(node*head,node*head2,int d) {
    node*temp=head;
    node*temp2=head2;
    while(d--) {
        temp=temp->next;
    }
    while(temp!=NULL && temp2!=NULL) {
        if(temp->data==temp2->data)
            return temp->data;
        temp=temp->next;
        temp2=temp2->next;
    }
    return -1;
}
int main() {
    int n1,n2;
    node*head=NULL;
    node*head2=NULL;
    cin>>n1;
    int l1=n1;
    while(n1--) {
        int d;
        cin>>d;
        insert(head,d);
    }
    cin>>n2;
    int l2=n2;
    int d = abs(l1-l2);
    while(n2--) {
        int d;
        cin>>d;
        insert(head2,d);
    }
    if(l1>=l2)
        cout<<interData(head,head2,d);
    else
        cout<<interData(head2,head,d);
	return 0;
}