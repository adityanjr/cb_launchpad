// avvinci
//#include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long int , long long int> P;
#define mod 1000000007 
#define MOD 1000000007
#define all(container) container.begin(),container.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin();it!=container.end();it++)
#define pb push_back
#define CLR(arr) memset(arr, 0, sizeof(arr))
#define mk make_pair
#define present(container,x) ((container).find(x) != (container).end())
#define inf 3234567891
//#define infl LLONG_MAX
#define fs first
#define sc second
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define siz size()
#define N 212345
const long long infl = 1e18+5;

ll m,n,p,q,x,y ,cn,k,tmp1,tmp,mx =0 ,f,val,sz,cntt,ans,t=1,i,j;
ll dp[1005][1005],a[26],cnt[26],mrk[26];
int mx1 =0 ;
string s;
ll rec( int ind , int len){
	mx1 = max(mx1 ,len);
	if(ind == n )
		return 1;
	ll re = 0;
	int it,fl = 0 ;
	if(dp[ind][len] != -1)
		return dp[ind][len];
	for( it= max(0,ind-len);it<=ind ;it++){
		if(len+1 >  a[s[it]-'a']){
			fl = 1;
			break;
		}
	}
	if(len ==0 ){
		re = rec(ind+1,len+1)%mod;
	}
	
	else if(fl == 0){
		re = (rec(ind+1, 1)%mod + rec(ind+1,len+1)%mod)%mod;

	}
	else{
		re = rec(ind+1,1)%mod;
	}
	dp[ind][len] =re;
	return re;
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>n;
fr(i,0,n)
	fr(j,0,n)
		dp[i][j] =-1;
cin>>s;
fr(i,0,26){
	cin>>a[i];
}
ll  ans1 = rec(0,0);
ll clen = 0 ,ff= 0 ;
ans  = 1;
fr(i,0,n){
	clen++ ;
	//ws(i);
	mrk[s[i]-'a'] =1;
	fr(j,0,26){
		if(mrk[j] && clen > a[j])
			ff =1;
	}
	if(ff){
		ff= 0;
		//ws(clen);
		mx = max(mx,clen-1);
		fr(j,0,26)
			mrk[j] = 0;
		clen=0;
		ans++;
		i--;
	}
	
}
// ws(mx1);
mx = max(mx,clen);
cout<<ans1<<"\n"<<mx1<<"\n"<<ans;
return 0;
}