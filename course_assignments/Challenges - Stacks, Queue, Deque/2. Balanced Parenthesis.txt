#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int main() {
    stack <char> s;
    string str;
    cin>>str;
    int n=str.length();
    for(int i=0; i<n; i++){
        if(str[i]=='(')
            s.push(str[i]);
        if(str[i]==')'){
            if(!s.empty() && s.top()=='('){
                s.pop();
            }
        }
        if(str[i]=='[')
            s.push(str[i]);
        if(str[i]==']'){
            if(!s.empty() && s.top()=='['){
                s.pop();
            }
        }
        if(str[i]=='{')
            s.push(str[i]);
        if(str[i]=='}'){
            if(!s.empty() && s.top()=='{'){
                s.pop();
            }
        }
    }
    if(s.empty() )
        cout<<"Yes";
    else
        cout<<"No";
	return 0;
}