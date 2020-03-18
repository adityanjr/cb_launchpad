#include iostream
using namespace std;

class node
class node{
public
    int data;
    node next;
    node(int d){
        data = d;
        next = NULL;
    }
};

length of linked list
int length(node head){
	int len =0;
	while(head != NULL){
		len++;
		head=head-next;
	}
	return len;
}

insert node at head
void insertAtHead(node &head, int d) {
    if(head == NULL) {
        When LL is empty
        head = new node(d);
        return;
    }
    Some LL already exists
    node temp = new node(d);
    temp-next = head;
    head = temp;
}

insert node at tail
void insertAtTail(node&head, int d){
	if(head == NULL){
		head = new node(d);
    	return;
	}
	node temp = head;
	while(temp-next != NULL){
		temp = temp-next;
	}
		temp-next = new node(d);	
}

insert node at Kth position
void insertAtK(node&head, int d, int k){
	if(k==0  head == NULL){
		insertAtHead(head, d);
		return;
	}
	else if(k=length(head)){
		insertAtTail(head, d);
		return;
	}
	else{
		int pos = 0;
		node temp = head;
		while(posk-1){
			temp = temp-next;
			pos++;
		}
		
		node n = new node(d);
		n-next = temp-next;
		temp-next = n;
		return;
	}
}

delete node at head
void deleteAtHead(node&head){
		if(head == NULL){
			return;
		}
		node temp = head;
		head = head-next;
		delete temp;
		return;
}

delete node at tail
void deleteAtTail(node&head){
	if(head == NULL  head-next == NULL){
		deleteAtHead(head);
		return;
	}
	node temp =head;
	while(temp - next - next != NULL){
		temp = temp-next;
	}
	delete temp-next;
	temp-next = NULL;
	return;
}

delete node at Kth position
void deleteAtK(node&head, int k){
	if(k==0  head==NULL  head-next == NULL){
		deleteAtHead(head);
		return;
	}
	else if(k = length(head)-1){
		deleteAtTail(head);
	}
	else{
		int pos =0;
		nodetemp = head;
		while(posk-1){
			pos++;
			temp=temp-next;
		}
		node tobeDeleted = temp-next;
		temp-next = temp-next-next;
		delete tobeDeleted;
		return;
	}	
}

print the linked list
void print(node head) {
    while(head!=NULL) {
        cout  head-data   ;
        head=head-next;
    }
    cout endl;
}


build the linked list
void buildList(node &head){
    int data;
    cindata;
    while(data != -1){
        insertAtTail(head,data);
        cindata;
    }
}

iteratively search given key in linked list
bool searchiter(node temp, int key){
    if(temp == NULL){
        return false;
    }

    while(temp != NULL){
        if(temp- data == key){
            return true;
        }
        temp = temp-next;
    }
     return false;
}

recursively search given key in linked list
bool searchrec(nodetemp, int key){
 base case
    if(temp == NULL){
        return false;
    }

     SELF WORK
    if(temp- data == key){
        return true;
    }
    else{
        return searchrec(temp-next, key);  rec case
    }


}

iteratively reverse given linked list
void reverseiter(node&head){
    if(head==NULL  head-next == NULL){
        return;
    }

    node prev = NULL;
    node curr = head;
    node nex = head-next;

    while(nex != NULL){
        curr - next = prev;
        prev = curr;
        curr = nex;
        nex = curr-next;
    }
    curr - next = prev;
    prev = curr;
    curr = nex;

    head = prev;
    return;
}


int main() {
    node head = NULL;

     insertAtHead(head,5);
     insertAtHead(head,3);
      insertAtTail(head,9);
      insertAtK(head, 6,2);
      deleteAtHead(head);
      deleteAtTail(head);
      insertAtHead(head,3);
      insertAtTail(head,9);
     deleteAtK(head,2);
    coutlength(head)endl;
   buildList(head);
 if(searchiter(head,5)){
     coutkey foundendl;
 }
 else{
     coutkey not foundendl;
 }
 print(head);
	reverseiter(head);
    print(head);

    return 0;
}