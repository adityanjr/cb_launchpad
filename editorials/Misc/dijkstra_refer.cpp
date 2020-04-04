// avvinci - April 17 
// #include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long int , long long int> P;
#define mod 1000000007 
#define pb push_back
#define mk make_pair
#define fs first
#define sc second
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define all(container) container.begin(),container.end()
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define siz size()
#define N 100004
const long long infl = 1e16+5;

ll m,n,q,x,y,k,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1;
ll a,b,s,c ,d[N];
vector< vector< P> > g(N);
priority_queue< P ,vector< P >,greater< P > > pq;

void dijkstra_my(){

	 while(!pq.empty()){
		P p = pq.top();
		pq.pop();
		int u = p.sc;
		ll dist = p.fs;
		if(dist > d[u]) continue;

		for(auto &it: g[u]){
				int v = it.sc;
				ll next_dist = dist + it.fs;
				if(next_dist < d[v]){
					d[v] = next_dist ; 
					pq.push({next_dist,v});
				}

		}
	}
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>t;
while(t--){
	cin>>n>>k>>x>>m>>s;
	fr(i,0,N)
		g[i].clear();

	fr(i,0,m){
		cin>>a>>b>>c;
		g[a].pb(mk(c,b));
		g[b].pb(mk(c,a));

	}
	fr(i,1,n+1)
		d[i] = infl;

	d[s] = 0 ;
    pq.push({0,s});
    dijkstra_my();
    mn = infl;
    fr(i,1,k+1)
    	mn = min(mn,d[i]);
    fr(i,1,k+1){
    	if(d[i] > (x+mn) ){
    		d[i] = x+mn;
    		pq.push({x+mn,i});
    	}
    }
    
    dijkstra_my();
    fr(i,1,n+1){
    	cout<<d[i]<<" ";
    }
    cout<<"\n";


}



return 0 ;
}