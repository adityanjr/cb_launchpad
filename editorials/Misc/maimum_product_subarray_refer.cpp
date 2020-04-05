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
#define N 1000004

const long long infl = 1e18+5;

ll n,m,k,q,x,y,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1;
ll a[N] ;
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>t;
while(t--){
	cin>>n;
	ans =0  ;
	ll mnp =1,mxp = 1;
	fr(i,0,n) {
		cin>>a[i] ;
	}
	fr(i,0,n){
		if(a[i] == 0 ){
			mxp = 1;
			mnp = 1;
		}
		else if(a[i] < 0  ) {
			ll v = mxp ;
			mxp = max(1LL ,mnp*a[i] ) ;
			mnp = v * a[i] ; 
		}
		else{
			mnp = min (1LL , mnp * a[i]) ;
			mxp = mxp*a[i];
		}
		
		// cout<<mxp<<" "<<mnp<<"\n";
		ans = max(ans , mxp);
	}
cout<<ans<<"\n";
}

return 0 ;
}