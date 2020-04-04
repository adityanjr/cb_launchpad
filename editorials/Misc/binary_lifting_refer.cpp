// avvinci - summer_17  home
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
#define siz(x)  (ll)x.size()
#define cnn continue
#define N 100004
const long long infl = 1e18+5;

ll m,n,q,x,y,k,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1;
ll a[N] ,ex[N],en[N],par[N] ,p[N][20] , lev[N]  ;
vector< vector < ll > > g(N) ,d(N);
void prep(){
	// fr(i,1,n+1){
	// 	for(j=0; (1<<j) <= n ; j++)
	// 		p[i][j] = -1;
	// }
	fr(i,1,n+1)
		p[i][0] = par[i];

	for(j=1; (1<<j) <= n; j++){
		fr(i,1,n+1){
			if(p[i][j-1] != 0)
				p[i][j] = p[ p[i][j-1] ][j-1] ; 
		}
	}
}

void dfs(int ver , int pr , int l){
	en[ver] = t;
	d[l].pb(t);
	lev[ver] = l ;
	t++;
	for(auto &it : g[ver]){
		if(it == pr ) cnn;
		dfs(it, ver , l + 1);
	}
	ex[ver] = t++;


}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n;
// memset(p,-1,sizeof(p));
fr(i,1,n+1){
	cin>>x;
	g[i].pb(x);
	g[x].pb(i);
	par[i] = x;
}

fr(i,1,n+1){
	if(par[i] == 0 ){
		dfs(i,0,0);
	}
}

prep();

cin>>m;
fr(i,0,m){
	cin>>x>>y;
	ll h = lev[x] ;
	for(j=20; j >= 0 ; j-- ){
		if(y == 0 ) break;
		if(p[x][j] == 0 || (1<<j) > y ) cnn;

		y -= (1<<j);
		x = p[x][j];
	}
	 // ws(y);
	ll s = 1  ;
	if(y == 0 )
		s = (ll)( lower_bound(all(d[h]) , ex[x]) - lower_bound(all(d[h]),en[x]) );
	cout<<s-1<<" ";
}

return 0 ;
}