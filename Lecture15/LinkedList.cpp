#include <iostream>
using namespace std;

//class node
class node {
public:
    int data;
    node* next;
    node(int d) {
        data = d;
        next = NULL;
    }
};

//length of linked list
int length(node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

//insert node at head
void insertAtHead(node *&head, int d) {
    if (head == NULL) {
        //When LL is empty
        head = new node(d);
        return;
    }
    //Some LL already exists
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

//insert node at tail
void insertAtTail(node*&head, int d) {
    if (head == NULL) {
        head = new node(d);
        return;
    }
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new node(d);
}

//insert node at Kth position
void insertAtK(node*&head, int d, int k) {
    if (k == 0 || head == NULL) {
        insertAtHead(head, d);
        return;
    }
    else if (k >= length(head)) {
        insertAtTail(head, d);
        return;
    }
    else {
        int pos = 0;
        node* temp = head;
        while (pos < k - 1) {
            temp = temp->next;
            pos++;
        }

        node* n = new node(d);
        n->next = temp->next;
        temp->next = n;
        return;
    }
}

//delete node at head
void deleteAtHead(node*&head) {
    if (head == NULL) {
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    return;
}

//delete node at tail
void deleteAtTail(node*&head) {
    if (head == NULL || head->next == NULL) {
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    while (temp -> next -> next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return;
}

//delete node at Kth position
void deleteAtK(node*&head, int k) {
    if (k == 0 || head == NULL || head->next == NULL) {
        deleteAtHead(head);
        return;
    }
    else if (k >= length(head) - 1) {
        deleteAtTail(head);
    }
    else {
        int pos = 0;
        node*temp = head;
        while (pos < k - 1) {
            pos++;
            temp = temp->next;
        }
        node* tobeDeleted = temp->next;
        temp->next = temp->next->next;
        delete tobeDeleted;
        return;
    }
}

//print the linked list
void print(node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


//build the linked list
void buildList(node* &head) {
    int data;
    cin >> data;
    while (data != -1) {
        insertAtTail(head, data);
        cin >> data;
    }
}

//iteratively search given key in linked list
bool searchiter(node* temp, int key) {
    if (temp == NULL) {
        return false;
    }

    while (temp != NULL) {
        if (temp-> data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//recursively search given key in linked list
bool searchrec(node*temp, int key) {
// base case
    if (temp == NULL) {
        return false;
    }

    // SELF WORK
    if (temp-> data == key) {
        return true;
    }
    else {
        return searchrec(temp->next, key); // rec case
    }


}

//iteratively reverse given linked list
void reverseiter(node*&head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    node* prev = NULL;
    node* curr = head;
    node* nex = head->next;

    while (nex != NULL) {
        curr -> next = prev;
        prev = curr;
        curr = nex;
        nex = curr->next;
    }
    curr -> next = prev;
    prev = curr;
    curr = nex;

    head = prev;
    return;
}


node* reverserec(node* head) {
    //base case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    node* smallLL = reverserec(head->next);
    node* curr = head;
    curr->next->next = curr;
    curr->next = NULL;
    return smallLL;

}


node* mid(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    node* fast = head->next;
    node* slow = head;
    while (fast != NULL && fast->next != NULL ) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // node* fast = head;
    // node* slow = head;
    // while(fast->next->next!=NULL && fast->next !=NULL ){
    //     fast = fast->next->next;
    //     slow = slow->next;
    // }
    return slow;
}


node* lastKth(node* head, int k) {
    node* fast = head;
    node* slow = head;
    int i = 1;
    while (i < k) {
        if (fast == NULL) {
            cout << "last kth element doesn't exist" << endl;
            return NULL;
        }
        fast = fast->next;
        i++;
    }
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
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
        c->next = merge(a->next, b);
    }
    else {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;

}

node* mergesort(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node* midpoint = mid(head);
    node *a = head;
    node *b = midpoint->next;
    midpoint->next = NULL;
    a = mergesort(a);
    b = mergesort(b);

    node* c = merge(a, b);
    return c;
}

bool detectCycle(node* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    node* slow = head;
    node* fast = head->next->next;

    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;

    }
    return true;

}


int main() {
    node *head = NULL;

    // insertAtHead(head,5);
    // insertAtHead(head,3);
    //  insertAtTail(head,9);
    //  insertAtK(head, 6,2);
    //  deleteAtHead(head);
    //  deleteAtTail(head);
    //  insertAtHead(head,3);
    //  insertAtTail(head,9);
    // deleteAtK(head,2);
    // cout<<length(head)<<endl;
    // buildList(head);
    // if(searchiter(head,5)){
    //     cout<<"key found"<<endl;
    // }
    // else{
    //     cout<<"key not found"<<endl;
    // }
    //  print(head);
    //reverseiter(head);
    //print(head);
    // cout<<mid(head)->data<<endl;
    // cout<<lastKth(head,3)->data<<endl;
    //  node *head2 = NULL;
    // buildList(head2);
    // print(head2);
    // node *headsorted = merge(head, head2);
    // print(headsorted);
    // node* head3 = NULL;
    //  buildList(head3);
    // print(head3);
    // head3 = mergesort(head3);
    // print(head3);
    node* head4 = NULL;
    head4 = new node(1);
    head4->next = new node(2);
    head4->next->next = new node(3);
    head4->next->next->next = new node(4);
    head4->next->next->next->next = new node(5);
    head4->next->next->next->next->next = new node(6);
    head4->next->next->next->next->next->next = new node(7);
    // head4->next->next->next->next->next->next->next = head4->next->next;
    head4->next->next->next->next->next->next->next = NULL;
    cout << detectCycle(head4) << endl;



    return 0;
}







