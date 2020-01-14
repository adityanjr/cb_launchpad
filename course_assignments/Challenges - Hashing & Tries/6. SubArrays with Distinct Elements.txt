#include <bits/stdc++.h>
using namespace std;
#define loop(x,n) for(int x=0; x<n; ++x)
#define ll long long

int sumoflength(int arr[], int n) 
{ 
    unordered_set<int> s; 
    int j = 0, ans = 0; 

    loop(i,n) 
    { 
        while (j < n && s.find(arr[j]) == s.end()) 
        { 
            s.insert(arr[j]); 
            j++; 
        }  
        ans += ((j - i) * (j - i + 1))/2; 
        s.erase(arr[i]); 
        ans = ans% 1000000007;
    } 
    return ans; 
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    loop(i,n){
        cin>>arr[i];
    }
    cout << sumoflength(arr, n) << endl;
}
