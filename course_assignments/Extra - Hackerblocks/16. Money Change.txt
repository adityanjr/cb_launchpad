#include <iostream>
using namespace std;
#define ll long long
#define MOD 1000000007

ll moneyChangeDP(ll coins[], ll n, ll amount){
    ll dp[n][amount+1] = {0};

    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<amount+1; j++){
            if(i==0) {
                if(j%coins[i] == 0) dp[i][j] = 1;
                else dp[i][j] = 0;
                continue;
            }
            if(j-coins[i] <0){
                dp[i][j] = dp[i-1][j]%MOD;
                continue;
            }
            dp[i][j] = (dp[i-1][j]%MOD + dp[i][j-coins[i]]%MOD)%MOD;
        }
    }
    cout <<  dp[n-1][amount]%MOD << endl;
}

int main(){
    ll t; cin>>t;
    for(ll q=0; q<t; q++){
        ll n; cin>>n;
        ll coins[n];
        for(ll i = 0; i<n; i++){
            cin>>coins[i];
        }
        ll amount; cin>>amount;
        moneyChangeDP(coins,n,amount);
    }
}