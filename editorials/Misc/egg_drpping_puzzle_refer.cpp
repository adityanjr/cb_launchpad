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

const long long infl = 1e18+5;

ll n,m,k,q,x,y,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1;
ll dp[N][N] ;

ll rec(ll n , ll k ){
	if(n <= 0 ) return k;
	if(k <= 0 ) return 0 ; 
	if(dp[n][k] != -1 ) return dp[n][k]; 

	ll i , re = infl;
	fr(i,1,k+1){
		re =  min ( re , 1LL + max(rec(n-1,i-1) , rec(n  ,k -i )) )  ;
	}
	dp[n][k] = re; 
	return re; 
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}


cin>>t;
while(t--){
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	cout<<rec(n,k)<<"\n";
}


return 0 ;
}