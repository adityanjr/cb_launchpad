// avvinci
// #include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long int , long long int> P;
#define mod 1000000007 
#define all(container) container.begin(),container.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin();it!=container.end();it++)
#define pb push_back
#define CLR(arr) memset(arr, 0, sizeof(arr))
#define mk make_pair
#define present(container,x) ((container).find(x) != (container).end())
//#define infl LLONG_MAX
#define fs first
#define sc second
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define siz size()
#define N 300004
const long long infl = 1e18+5;

ll m,n,p,q,x,y ,cn,k,tmp1,tmp,mx =-1 ,mn=infl,f,val,sz,sm,cnt,ans,t=1,ind = -1,ci,lt;
ll a[20],dp[ (1LL << 18)][100] ;

ll rec( ll mask , ll rem){
	if(mask == lt){
		// ws(mask);
		if( rem == 0 )
			return 1;
		return 0 ;
	}
	if(dp[mask][rem] != -1)
		return dp[mask][rem];


	ll i,re=0;
	fr(i,0,cnt){

		if(mask == 0  && a[i] == 0 ) continue;

		if( (mask & (1LL<<i)) != 0 ) continue;
	
		// ???????????????????

		if( i>0 && (mask & (1LL<<(i-1)))== 0 && a[i] == a[i-1] ) continue;

		// ???????????????????
		
		 re += rec( (mask | (1LL<<i) ), (rem*10 + a[i] )%m ) ;

	}
	dp[mask][rem] =re;
	return re;
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
ll  i,j ;
fr(i,0,(1LL<<18)){
	fr(j,0,100)
		dp[i][j]=-1;
}
cin>>n>>m;
while(n > 0 ){
	a[cnt] = n%10;
	n /= 10;
	cnt++;
} 
sort(a,a+cnt);

 lt = (1LL << cnt) -1;

ll re = rec(0,0);

cout<<re;

return 0 ;
}
