#include <bits/stdc++.h>
using namespace std;
#define loop(x,n) for(ll x=0; x<n; ++x)
#define ll long long

void insertInMap(unordered_map<ll,ll> &m, ll data){
    if(m.count(data)) m[data]++;
    else m[data]=1;
}

int main(){
    ll n; cin>>n;
    unordered_map<ll,ll> m;

    loop(j,n){
        ll d; cin>>d;
        insertInMap(m,d);
    }

    ll maxdata= m.begin()->first ;
    ll maxfreq= m.begin()->second ;

    for(auto it:m){
        if(it.second >= maxfreq) maxdata = it.first;
    }
    cout << maxdata ;
}