#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class stack{
 	vector<T> v;
public:
 	void push(T data){
 		v.push_back(data);
 	}
	T top(){
		if(v.empty()){
			cout<<"stack underflow"<<" ";
		}
		return v[v.size()-1];
	}
	T pop(){
		if(v.empty()){
			cout<<"stack underflow"<<" ";
			return NULL;
		}
		T topElement = top();
		v.pop_back();
		return topElement;
	}
};
int main(){
	stack<int> st;
	st.push(5);
	st.push(4);
	st.top();
	st.top();
	cout<<"--------------------"<<endl;
	return 0;
}