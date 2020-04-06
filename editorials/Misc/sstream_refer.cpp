// avvinci
// march 17 
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

ll m,n,p,q,x,y ,cn,k,tmp1,tmp,mx =-1 ,mn=infl,f,val,sz,sm,cnt,t=1,i,j,ind = -1,ci;
string a ,b ;
ll ans[20] ,pr[20] ,dp[20], l, r; 
inline std::string to_string (const ll& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>tmp>>tmp1;
tmp--;

std::stringstream strstream;
strstream << tmp1 <<' ' <<tmp;
strstream >> b >> a;


// ws(a);
// ws(b);
dp[0]=1;
ans[1] = 9 ;
ans[2] = 9 ;
fr(i,3,19){
	ans[i] = 10LL*ans[i-1];

}
fr(i,1,19){
	pr[i] = ans[i] +  pr[i-1];
	dp[i] = 10LL*dp[i-1];
}

n = (ll)a.siz;
m= (ll)b.siz;
l += pr[n-1];
r += pr[m-1];
// ws(r);
fr(i,0,n-1){
	if(a[i] == '0') continue;
	
	sm = a[i]-'0' ;
if(i==0)
		sm--;
	l += sm *(dp[n-2-i]);
	// ws(l);

}
if(a[n-1] >= a[0]) l++;
if(n==1) l = tmp;
// ws(l/);

fr(i,0,m-1){
	if(b[i] == '0' ) continue;
	sm = b[i] -'0';
	if(i==0)
		sm--;
	r += sm*(dp[m-2-i]);
	// ws(r);
}
if(b[m-1] >= b[0]) r++;
if(m==1) r = tmp1;

cout<<r-l;

return 0 ;
}