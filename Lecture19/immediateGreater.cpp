#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int arr[]= {12,9,8,15,5,7};
    int n= sizeof(arr)/sizeof(int);
    stack<int> st;
    st.push(arr[0]);
    for(int i=1; i<n; i++){
        if(st.top()>arr[i])
            st.push(arr[i]);
        else if (st.top()<arr[i]){
            while(!st.empty() && st.top()<arr[i]){
                cout<< st.top() <<" "<<arr[i]<<endl;
                st.pop();
            }
            st.push(arr[i]);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" "<<-1<<endl;
        st.pop();
    }
}