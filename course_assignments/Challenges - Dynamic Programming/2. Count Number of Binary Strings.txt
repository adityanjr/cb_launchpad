#include <iostream>
using namespace std;
#define ll long long

int main(){

    ll t; 
    cin>>t;

    ll dp[2][100];

    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[0][1] = 1;
    dp[1][1] = 1;

    for(ll j=2; j<100; j++){
        dp[0][j] = dp[0][j-1] + dp[1][j-1];
        dp[1][j] = dp[0][j-1];
    }

    while(t--){
        ll n; cin>>n;
        cout << dp[0][n] + dp[1][n] <<endl;
    }
}