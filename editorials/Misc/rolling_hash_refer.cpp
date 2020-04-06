// avvinci
// march 17 home
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
#define ll  long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define siz size()
#define N 300004
const long long infl = 1e18+5;

ll m,n,q,x,y ,cn,k,tmp1,mx =-1 ,mn=infl,f,val,sz,sm,cnt,ans,i,j,ind = -1,ci;
ll a[26] ;
string s, p,t;
set< ll > st;
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
ll aa = 6364136223846793005,h;
m = 1LL<<60;
cin>>s;
 n = (ll)s.siz; 
cin>>p;
cin>>k;
fr(i,0,26){
	a[i] = 1 - (p[i]-'0');
} 
fr(i,0,n){
	
	ci= 0 ;
	h =0 ;
	fr(j,i,n){
		ci += a[s[j]-'a'];
		if(ci > k)
			break;
		 h =  (h*aa+ (s[j]-'a'+1) )%m;
		// ws(h);
		st.insert(h);

	}
	// ws(st);

}
 // ws(st);
cout<<(ll)st.siz;

return 0 ;
}
