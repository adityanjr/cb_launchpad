#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(x,n) for(ll x=0; x<n; ++x)

class Pair{
public:
    int value;
    int freq;

    Pair(int data){
        value = data;
        freq = 0;
    }
};

class PairCompare{
public:
    bool operator()(Pair a, Pair b){
        if(a.freq != b.freq) return a.freq<b.freq; //max heap on freq
        else return a.value>b.value;  //min heap on data
    }
};
void printQue(priority_queue<Pair,vector<Pair>,PairCompare> pq, int k){  
    while(k>0 && !pq.empty()){
        Pair p = pq.top();
        cout<< p.value <<" ";
        pq.pop();
        k--;
    }

}
vector<Pair> updateVector(vector<Pair> v, int d){
    loop(i,v.size()){
        if(d==v[i].value){
            v[i].freq++;
            return v;
        }
    }
    Pair p(d);
    v.push_back(p);
    return v;
}

int main(){
    int t; cin>>t;
    loop(j,t){
        int n,k;
        cin >>n>>k;
        vector<Pair> v;

        loop(i,n){
            int d; cin>>d;
            v = updateVector(v,d);

            priority_queue<Pair,vector<Pair>,PairCompare> pq;

            loop(w,v.size()){
                pq.push(v[w]);
            }
            printQue(pq,k);
        }
        cout<<endl;
    }
}