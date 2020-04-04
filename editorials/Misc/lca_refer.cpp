// avvinci - summer_17  
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
#define sz(x)  (ll)x.size()
#define N 100004

const long long infl = 1e18+5;

ll n,m,k,q,x,y,mx =-1,mn=infl,f,val,sz,sm,cnt,i,j,ind=-1;
ll a[N], ans[N], l[N] ,  p[N][50] ,t[N] ;
std::vector< vector< ll >  >  g(N);
std::map<P, ll> mp;

void prep(){

	int i  ,j ;

	memset(p,-1,sizeof(p));
	fr(i,1,n+1) 
		p[i][0] = t[i];
	
	for(j=1; 1<<j < n ; j++){
		fr(i,1,n+1){
			if(p[i][j-1] != -1)
				p[i][j] = p[p[i][j-1]][j-1];
		}
	}

}
void dfs(int ver ,int par) {
	// sz[ver] = 
	for(auto it : g[ver]){
		if(it == par) continue ; 
		dfs(it,ver) ; 

		a[ver] += a[it];

		if(mp.find(mk(ver,it)) != mp.end()){
			ans[mp[mk(ver,it)]]  =a[it] ;
		}
	}
}

void dfs1(int ver, int par){
	t[ver] = par ; 
	l[ver] = l[par] +1 ;
 	for(auto it : g[ver]) 
		if(it == par ) continue ; 
	else
		dfs1(it, ver) ; 

}

ll lca(int a1 ,int a2){

	int i ,lg; 
	if(l[a1] < l[a2] )
		swap(a1,a2);
	for(lg = 1 ; 1<<lg <= l[a1] ;lg++);

	lg--;
	for(i= lg ; i>= 0 ; i--){
		if(l[a1] - (1<<i) >= l[a2])
			a1 = p[a1][i];
	}
	if(a1 == a2) return a1;

	for(i= lg ; i>=0 ;i--){
		if(p[a1][i] != -1 && p[a1][i] != p[a2][i]){
			a1 = p[a1][i];
			a2 = p[a2][i];
		}
	}

	return t[a1];

}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n;
fr(i,0,n-1) {
	cin>>x>>y;
	mp[{x,y}] = i ; 
	mp[{y,x}] = i;
	g[x].pb(y);
	g[y].pb(x);
}

l[0] =-1;
dfs1(1,0);
t[1] = -1;
prep();
cin>>m ; 
fr(i,0,m){
	cin>>x>>y ; 
	val = lca(x,y) ; 
	// ws(val);
	a[val] -= 2; 
	a[x]++; a[y]++;
}
dfs(1,0);

fr(i,0,n-1) cout<<ans[i]<<" "; 


return 0 ;
}