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
/* Reverses the linked list in groups 
of size k and returns the pointer 
to the new head node. */
Node *reverse (Node *head, int k)  {
    Node* current = head;  
    Node* next = NULL;  
    Node* prev = NULL;  
    int count = 0;  
      
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)  {
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
      
    /* next is now a pointer to (k+1)th node  
    Recursively call for the list starting from current.  
    And make rest of the list as next of first node */
    if (next != NULL)  
    head->next = reverse(next, k);  
  
    /* prev is new head of the input list */
    return prev;  
}  
  
/* Function to push a node */
void push(Node* &head, int d)  {
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
    Node* head = NULL;
    int n, k, data;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>data;
        push(head, data);
    }    

    head = reverse(head, k);   
    printList(head);  
    return(0);  
}  