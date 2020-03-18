#include <iostream> 
using namespace std; 
class Node  {
    public: 
    int data;  
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};  
Node* merge(Node* a, Node*b){
    if(a==NULL) return b;
    else if(b==NULL) return a;
    Node* c;
    if(a->data < b->data){
        c=a;
        c->next = merge(a->next, b);
    }
    else {
        c=b;
        c->next = merge(a, b->next);
    }
    return c;
}
  
void push(Node* &head, long long d)  {
    if(head == NULL){
        head = new Node(d);
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new Node(d);
}  
  
void printList(Node *head)  {
    while (head != NULL)  {
        cout<<head->data<<" ";  
        head = head->next;
    }  
}  

int main()  {
    int t;
    cin>>t;
    while(t--){
        Node* head1 = NULL;
        Node* head2 = NULL;
        Node* res = NULL;
        long long n1, n2, data;
        cin>>n1;
        for(int i=0; i<n1; i++){
            cin>>data;
            push(head1, data);
        }
        cin>>n2;
        for(int i=0; i<n2; i++){
            cin>>data;
            push(head2, data);
        }
        res = merge(head1, head2);
        printList(res);
        cout<<endl; 
    } 
    return 0;  
}