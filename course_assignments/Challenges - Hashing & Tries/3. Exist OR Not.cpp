#include<iostream>
#include<map>
#define ll long long int
using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        ll n; cin>>n;

        map<ll,bool> myPair;
        for(ll i=0;i<n;i++){
            ll pair;
            cin>>pair;
            myPair[pair]=true;
        }

        ll num; cin>>num;
        while(num--){
            ll a; cin>>a;
            if(myPair.count(a))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
}