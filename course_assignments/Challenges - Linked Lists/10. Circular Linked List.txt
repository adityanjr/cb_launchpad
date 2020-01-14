#include <iostream>
#include <set>
using namespace std;
class Node{
	public:
		int data;
		Node * next;
		Node(int value=0):data(value), next(NULL){}

};

class LL{
	private:
		Node * head;
		//Node * tail;
	public:
		LL():head(NULL){}//, tail(NULL){}
		LL(Node* h):head(h){}
		void print(){
			Node *temp = head;
			while(temp){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
		void insert_at_tail(int);
		void make_list();
		
};


void LL::insert_at_tail(int value){
	Node *n  = new Node(value);
	Node *temp = head;
	if(!temp){//empty list
		this->head = n;
		return;
	}
	while( temp and temp->next){
		temp = temp->next;
	}
	temp->next = n;
}

void LL::make_list(){
	// insert till -1
	int n;
	cin>>n;
	set<int> s;
	while(n!=-1){
		if(s.find(n) ==s.end()){
			this->insert_at_tail(n);
			s.insert(n);
		}
		cin>>n;
	}
}

int main(){
	LL a;
	a.make_list();
	a.print();
	return 0;
}