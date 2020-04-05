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
#define N 104
#define M 100004

const long long infl = 1e8+5;

ll n,m,k,x,y,mx =-1,mn=infl,f,sz,sm,cnt,ans,t=1,i,j,ind=-1;
ll a[N] , maxflow;
int isprime[N],val[N],cap[N][N],flow[N][N],path[N] ;
bool b[M] ; 
std::vector<vector< int > >   g(N);
std::vector<ll> v,odd,even;

void prep(){

	ll i ,j;
	fr(i,2,M){
		if(b[i] ) continue ;
		for(j= i+i ;j< M; j += i)
			b[j] = 1;
		v.pb(i);
	}
}

int S = 0 , T = N - 1;
int augment(int v , int mf){
	if(v== S){
		maxflow += mf ; 
		return mf;
	}

	int u = path[v];
	bool backflow = false ; 
	if(flow[v][u] > 0  ) backflow = true ;
	if(backflow){
		mf = min(mf, flow[v][u]);
	}
	else{
		mf = min(mf , cap[u][v] - flow[u][v]);
	}

	mf = augment(u,mf);
	if(backflow){
		flow[v][u] -= mf ; 
	}
	else
		flow[u][v] += mf ;

	return mf ;
}

void edmondskarp(){
	while(true){
		int i ; 
		queue<int > q ; 
		memset(path,-1,sizeof(path));
		q.push(S);
		path[S] = S ; 
		bool augmented = false ; 

		while(!q.empty()){
			int u = q.front(); 
			q.pop();
			fr(i,0,sz(g[u])){
				int v = g[u][i];
				if(path[v] != -1) continue ;
				if(cap[u][v] - flow[u][v] > 0  ||  flow[v][u] > 0 ){
						path[v] = u  ;
						if(v ==T){
							augment(T,infl);
							augmented =true ;
							break ; 
						}
						else
							q.push(v);
					}	
			}
			if(augmented) break ; 
 		}
		if(!augmented ) break ; 
	}
}

void solve_maxflow(){
	int i,j ; 
	fr(i,0,m){
		int  u= odd[i];
		int v = even[i];
		cap[S][u] = val[u];
		cap[v][T] = val[v] ;
		cap[u][v] = min(val[u],val[v]);
	}

	fr(i,0,N)
		fr(j,0,N)
			flow[i][j] = 0 ; 

	edmondskarp();
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

prep() ; 
cin>>n>>m;
fr(i,1,n+1) cin>>a[i] ; 

fr(i,0,m){
	cin>>x>>y;
	if(x%2 == 0 ) swap(x,y);
	even.pb(y);
	odd.pb(x); 
}
fr(i,0,m){
	g[S].pb(odd[i]);
	g[odd[i]].pb(S);
	g[T].pb(even[i]);
	g[even[i]].pb(T);
	g[even[i]].pb(odd[i]);
	g[odd[i]].pb(even[i]);
	cap[S][odd[i]] = infl ; 
	cap[even[i]][T] = infl; 
}

maxflow = 0 ;
memset(isprime , 1, sizeof(isprime));
fr(i,0,sz(v)){
	bool ok = false ;
	memset(val,0,sizeof(val)); 
	fr(j,1,n+1){
		int temp = a[j];
		cnt = 0 ;
		while(temp > 1 && temp%v[i] ==0 ){
			cnt++;
			temp /= v[i];
		}
		if(cnt > 0 ){
			isprime[j] = 0 ;
			ok = true ; 
		}
		val[j] = cnt;
	}

	if(ok){
		solve_maxflow();
	}

}

std::vector<ll> extra;
fr(j,1,n+1){
	bool ok = true; 
	if(isprime[j] == 0 || a[j] == 1) continue ;
	fr(i,0,sz(extra)){
		if(extra[i] == a[j]) {
			ok= false ; break;
		}
	}
	if(!ok ) continue ; 
	ok = false;
	extra.pb(a[j]) ;
	memset(val,0,sizeof(val));

	fr(i,1,n+1){
		int temp = a[i];
		cnt = 0 ;
		while(temp > 1 && temp%a[j] ==0 ){
			cnt++;
			temp /= a[j];
		}
		if(cnt > 0 ){
			ok = true ; 
		}
		val[i] = cnt;

	}
	// fr(i,1,n+1)	ws(val[i]);
	if(ok){
		solve_maxflow();
	}
}

cout<<maxflow;
return 0 ;
}