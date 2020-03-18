#include <iostream>
#include <climits>
using namespace std;
#define ll long long

ll arr[150];
ll dp[150][150];

ll sums(ll s, ll e){
    ll ans = 0;
    for(ll i=s; i<=e; i++){
        ans += arr[i];
        ans %= 100;
    }
    return ans;
}

ll mixtures(ll i, ll j){
    if(i>=j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = INT_MAX;
    for(ll k=i; k<=j; k++) {
        dp[i][j] = min(dp[i][j], mixtures(i,k)+mixtures(k+1,j)+sums(i,k)*sums(k+1,j));
    }
    return dp[i][j];
}

int main(){
    ll n; cin>>n;
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }

    for(ll i=0; i<150; i++){
        for(ll j=0; j<150; j++){
            dp[i][j] = -1;
        }
    }
    cout <<  mixtures(0,n-1);
}