#include<iostream>
#include<stack>
using namespace std;
void printSpan(int arr[], int n){
    stack <int> s;
    int ans[100] = {0};
    for(int day=0; day<n; ++day){
        while(!s.empty() && arr[s.top()] < arr[day]){
            s.pop();
        }
        ans[day] = s.empty() ? day+1 : day-s.top();
        s.push(day);
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"END";
}
int main() {
    int n;
    cin>>n;
    int arr[100];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    printSpan(arr,n);
	return 0;
}