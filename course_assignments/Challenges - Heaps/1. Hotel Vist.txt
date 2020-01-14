#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(x,n) for(ll x=0; x<n; ++x)

class Hostel{
public:
    ll x;
    ll y;
    ll id;
    Hostel(ll a, ll b, ll i){
        x =  a;
        y =  b;
        id = i;
    }
    ll distance(){
        return x*x+y*y ;
    }

};

class HostelCompare{
public:
    bool operator()(Hostel a, Hostel b){
        return a.distance() < b.distance() ; //maxheap
    }
};

void prllQue(priority_queue <Hostel,vector<Hostel>,HostelCompare> pq){
    while(!pq.empty()){
        Hostel h = pq.top();
        cout<< h.distance() <<endl;
        pq.pop();
    }

}
void prllKthnearest(priority_queue <Hostel,vector<Hostel>,HostelCompare> pq, ll k){
    Hostel h = pq.top();
    cout<< h.distance() <<endl;
}

int main(){
    ll n; ll k;
    cin>>n>>k;

    priority_queue <Hostel,vector<Hostel>,HostelCompare> pq;
    ll cs = 0;

    loop(i,n){
        ll type;
        cin>>type;

        if(type == 2) {
            // prllQue(pq);
            // return 0;
             prllKthnearest(pq,k);
        }
        else {
            ll x,y;
            cin>>x>>y;
            Hostel h(x,y,i);

            if(cs<k){
                pq.push(h);
                cs++;
            }
            else{
                Hostel top = pq.top();
                if(h.distance()<top.distance()){
                    pq.pop();
                    pq.push(h);
                }
            }
        }
    }
}