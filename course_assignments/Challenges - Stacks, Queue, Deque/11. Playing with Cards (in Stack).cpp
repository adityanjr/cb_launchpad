#include<iostream>
#include<stack>
using namespace std;

int Qth_prime_number(int Q){
	int count=0;
	int N,i;
	for (N=2; ;N++) {
        for (i=2;i<N;i++) {
            if (N%i==0)
                break;
        }
	    if (i==N)
            count++;

	    if (count==Q)
            return N;
    }
}

void output(stack<int> st){
	while (st.empty()==false) {
        cout<<st.top() <<endl;
	    st.pop();
    }
}

void playing_with_cards(stack<int>& st, int i, int Q){
	stack<int> A,B;
	int top;
    if (i==Q) return;

	int prime=Qth_prime_number(i+1);
	while (st.empty()==false) {
        if (st.top()%prime==0) {
            top=st.top();
	        st.pop();
	        B.push(top);
        }
	    else {
            top=st.top();
	        st.pop();
	        A.push(top);
        }
    }
	output(B);
    if (i==Q-1)
        output(A);

	playing_with_cards(A,i+1,Q);
}

int main(){
	int N,Q,x;
	stack<int> cards;
	cin>>N >>Q;
	for (int n=0;n<N;n++) {
        cin>>x;
	    cards.push(x);
    }
	playing_with_cards(cards,0,Q);
}