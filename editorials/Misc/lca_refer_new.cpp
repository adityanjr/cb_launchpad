// avvinci - sem_7 
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
// #define x.sz  (ll)x.size()
#define N 100004
#define M 11
#define LG 17

const long long infl = 1e7+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans,mx = -1,mn = infl ;
// int a[N]/ ;
vector< int > g[N]  ;
int d[N] ,par[LG][N] ; 
struct node{
	int a[M] ; 
	node(){
		int i ; 
		fr(i,0,M) a[i] = infl;
	}
	void insert(int x){
		a[M-1] = x;
		sort(a,a+M) ;
	}
}vals[LG][N] ;
 node mrg( node x , node y){
 	node ans = x ; 
 	int i ;
 	fr(i,0,M){
 		ans.insert(y.a[i]) ; 
 	}
 	return ans ;
 }

 void dfs( int u, int p ){
 	par[0][u] = p ;
 	fr(i,1,LG){
 		par[i][u] = par[i-1][par[i-1][u]];
 		vals[i][u] = mrg(vals[i-1][u] , vals[i-1][par[i-1][u]]) ; 
 	}

 	for(auto it :g[u]){
 		if(it == p ) continue; 
 		d[it] = d[u] + 1; 
 		dfs(it,u);
 	}
 }
int get_parent(int v ,int k){
	int i ; 
	fr(i,0,LG){
		if((1<<i) & k ){
			v = par[i][v] ; 
		}
	}
	return v ;
}
node get(int v  ,int k ){
	int i ;
	node ans ; 
	fr(i,0,LG){
		if((1<<i)&k){
			ans = mrg(ans,vals[i][v]) ; 
			v = par[i][v];
		}
	}
	return ans;
}

int lca( int x ,int y ){
	if(d[x] < d[y]) swap(x,y);
	x = get_parent(x, d[x] - d[y]) ;
	if(x == y ) return x ;
	int i ; 
	for(i=LG-1 ;i>=0;i--){
		if(par[i][x] != par[i][y]){
			x = par[i][x];
			y = par[i][y];
		}
	}
	return par[0][x];
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>n>>m>>q;
fr(i,0,n-1){
	cin>>x>>y;
	x--; y--;
	g[x].pb(y);
	g[y].pb(x); 
}
fr(i,0,m){
	cin>>x;
	x--;
	vals[0][x].insert(i);
}
dfs(0,0);
while(q--){
	cin>>x>>y>>k;
	x--; y--; 
	int val = lca(x,y) ; 
	node n1  = get(x , d[x] - d[val]);
	node n2 = get(y,d[y] - d[val] + 1);
	node ans = mrg(n1,n2);
	i = 0 ; 
	while (i < k &&  ans.a[i] < m  ){
		i++ ; 
	}
	k = i ; 
	cout<<k<<" " ; 
	i = 0 ; 
	while (i < k ){
		cout<<ans.a[i] +1 <<" ";
		i++ ; 
	}
	cout<<"\n" ; 
}
return 0 ;
}