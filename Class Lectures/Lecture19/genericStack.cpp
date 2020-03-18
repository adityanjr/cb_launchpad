#include <iostream>
#include <vector>

using namespace std;

template<typename T, typename P>
//template<typename T>
class stack
{
	vector<pair<T, P> > v;
	//vector<P> v1;
public:
	void push(T name, P marks){
		pair<T, P> student = make_pair(name, marks);
		v.push_back(student);
	}
	pair<T, P> pop(){

		if(v.empty()){
			pair<T, P> student;
			cout<<"stack is underflow"<<endl;
			return student;
		}
		pair<T, P> topElement = top(); 
		 v.pop_back();
		 return topElement;
	}
	pair<T, P> top(){
		if(v.empty()){
			pair<T, P> student;
			cout<<"stack is underflow"<<endl;
			return student;
		}
		return v[v.size()-1];
	}
	
	
};
int main(int argc, char const *argv[])
{
	stack<string, int> st;
	//stack<pair<int, int> >st;
	//stack<int> st;
	st.push("abcd", 90);
	st.push("efgh",80);
	st.push("ijkl",100);
	cout<<st.top().first<<" "<<st.top().second<<endl;
	st.pop();
	cout<<st.top().first<<" "<<st.top().second<<endl;
	st.pop();
	cout<<st.top().first<<" "<<st.top().second<<endl;
	st.pop();
	cout<<st.top().first<<" "<<st.top().second<<endl;
	st.pop();
	return 0;
}

