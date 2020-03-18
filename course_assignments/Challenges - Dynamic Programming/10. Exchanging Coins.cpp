#include<iostream>
#include<vector>
using namespace std;
#define ll long long

ll calculate(vector<ll> &dp, ll n){
    if(n<10)
        return n;

    if(n<1000000){
        if(dp[n])
            return dp[n];

        else{
            ll x = calculate(dp,n/2) + calculate(dp,n/3) + calculate(dp,n/4);
            dp[n]=max(n,x);
            return dp[n];
        }
    }
    ll x = calculate(dp,n/2) + calculate(dp,n/3) + calculate(dp,n/4);
    return max(n,x);
}

int main(){
    ll i,j,k,n;
    ll x,y,z;
    int t;

    vector<long long int> dp(1000000,0);
    cin>>n;
    cout<<calculate(dp,n)<<endl;
    return 0;
}