#include <iostream>
#include <vector>

using namespace std;

class stack
{
	vector<int> v;
public:
	void push(int data){
		v.push_back(data);
	}
	int pop(){
		if(v.empty()){
			cout<<"stack is underflow"<<endl;
			return -1;
		}
		int topElement = top(); 
		 v.pop_back();
		 return topElement;
	}
	int top(){
		if(v.empty()){
			cout<<"stack is underflow"<<endl;
			return -1;
		}
		return v[v.size()-1];
	}
	
	
};


int main(int argc, char const *argv[])
{	stack st;
	st.push(3);
	st.push(4);
	st.push(5);
	//st.v[1] = 10;
	cout<<st.top()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	return 0;
}




