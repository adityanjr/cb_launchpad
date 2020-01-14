#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(x,n) for(ll x=0; x<n; ++x)

class Pair{
public:
    ll data;
    ll k;

    Pair(ll d, ll a){
        data = d;
        k =a;
    }
};

class PairCompare{
public:
    bool operator()(Pair a, Pair b){
        return a.data>b.data;
    }
};

void prllQue(priority_queue<Pair,vector<Pair>,PairCompare> pq){
    while(!pq.empty()){
        Pair h = pq.top();
        cout<< h.data <<endl;
        pq.pop();
    }

}

int main(){
    ll k,n;
    cin>>k>>n;
    ll arr[k+1][n+1];
    vector<ll> finalArr;

    loop(i,k){
        loop(j,n){
            cin>>arr[i][j];
        }
    }

    loop(i,k){
        arr[i][n] = 1000000000000000;
    }

    ll poller[100] = {0};
    // pq of size k //min heap
    priority_queue<Pair,vector<Pair>,PairCompare> pq;

    loop(i,k){
        Pair p(arr[i][poller[i]],i);
        pq.push(p);
        poller[i]++;
    }

    //prllQue(pq);        //
    //return 0;

    while (finalArr.size()<k*n) {
        Pair p = pq.top();
        pq.pop();
        finalArr.push_back(p.data);

        Pair p1(arr[p.k][poller[p.k]],p.k);
        pq.push(p1);
        poller[p.k]++;
    }

    loop(i,finalArr.size()){
        cout<< finalArr[i] <<" ";
    }
}