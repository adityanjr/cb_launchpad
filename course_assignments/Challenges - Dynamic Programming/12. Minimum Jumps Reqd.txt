#include <iostream>
#include <climits>
using namespace std;
#define ll long long

ll jumps(ll arr[], ll s, ll e){
    if(s>e) return 0;
    if(arr[s] >= e-s) return 1;

    else {
        ll ans = INT_MAX;
        for(ll i=1; i<=arr[s]; i++){
            ll temp = 1 + jumps(arr,s+i,e);
            if(temp < ans) ans = temp;
        }
        return ans;
    }
}

int main(){
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll arr[n];
        for(ll i=0; i<n; i++) cin>>arr[i];
        cout << jumps(arr,0,n-1) << endl;
    }
}