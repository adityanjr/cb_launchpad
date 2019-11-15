#include<iostream>
#include<stack>
using namespace std;
void print(stack<int>st) {
	while(!st.empty()) {
		cout<<st.top()<<endl;
		st.pop();
	}
}
void insert(stack<int> &st,int x) {
	if(st.empty()) {
		st.push(x);
        return;
	}
	else {
		int y=st.top();
		st.pop();
		insert(st,x);
		st.push(y);
	}
}
void reverse(stack<int> &st) {
	if(st.empty())
		return;
	else {
		int x=st.top();
		st.pop();
		reverse(st);
		insert(st,x);
	}

}
int main() {
	stack<int>st;
	int n;
	cin>>n;
	int x;
	for(int i=0; i<n; i++) {
		cin>>x;
		st.push(x);
	}
	reverse(st);
	print(st);
    return 0;
}