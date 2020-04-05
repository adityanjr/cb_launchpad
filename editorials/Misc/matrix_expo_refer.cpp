// avvinci - summer_17 home
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

const long long infl = 1e18+5;

ll n,m,k,q,x,y,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1;

vector<vector< ll> >  matmul(vector<vector< ll> >  &a , vector<vector< ll> >  &b){
	
	ll n = sz(a);
	vector<vector<ll> > ans(n, vector<ll>(n,0));
	ll i , j ,k; 

	fr(i,0,n){
		fr(j,0,n){
			fr(k,0,n){
				ans[i][j] += a[i][k]*b[k][j];
				ans[i][j] %= mod;

			}
		}
	}

	fr(i,0,n)
	fr(j,0,n)
		b[i][j] = ans[i][j] ; 
	return b; 

}
vector<ll> mymul( vector<vector< ll> >  &a , vector<ll> &v){

	ll i;
	ll sm = 0 ;
	ll n = sz(v);
	ll ans[n];
	fr(i,0,n){
		sm = 0 ; 
		fr(j,0,n){
			sm += v[j]*a[j][i];
			sm %= mod;
		}
		ans[i] = sm;
	}

	fr(i,0,n) v[i] = ans[i];
	return  v; 

}

vector<vector< ll> > matexp(vector<vector< ll> >  &a , ll k ){
	ll m = k ; 
	ll i , j ; 
	int n = sz(a);
	vector<vector<ll> > ans(n, vector<ll>(n,0));

	fr(i,0,n) ans[i][i] = 1;
	while(m > 0 ){
		if(m%2 == 1){
			matmul(a,ans);
		} 
		
		matmul(a,a);
		m /= 2;		
	}

	fr(i,0,n)
		fr(j,0,n)
			a[i][j] = ans[i][j] ; 
	return a ; 

}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n>>k;
ll a[n]  ;
std::vector<ll> v(n);
vector<vector<ll> > z(n, vector<ll>(n,0));

fr(i,0,n){
	cin>>a[i];
}

fr(i,0,n){
	fr(j,0,n){
		val = a[i]^a[j]; 
		cnt = 0 ; 
		while(val > 0 ) {
			cnt += val%2;
			val /=2;
		}
		// ws(cnt);
		if(cnt%3 == 0 ) z[i][j]  = 1;
	}
}


fr(i,0,n) v[i] = 1;
// ws(z);
// cout<<"\n";
matexp(z,k-1) ;
// ws(z);
v = mymul(z,v) ; 
// ws(v);

fr(i,0,n){
	 ans += v[i];
	 ans %= mod;
}

cout<<ans;

return 0 ;
}