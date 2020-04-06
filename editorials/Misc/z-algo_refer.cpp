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
#define N 400004
const long long infl = 1e18+5;

ll m,n,p,q,x,y ,cn,k,tmp1,tmp,mx =-1 ,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind = -1,ci;
ll a[N] ,b[N],z[N];
vector< ll > v;

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n>>m;
if(m == 1){
	cout<<n;
	return 0;
}
fr(i,0,n)
	cin>>a[i];
fr(i,0,m){
	cin>>b[i];
} 
fr(i,1,m){
	v.pb(b[i]-b[i-1]);
}
v.pb(infl);
fr(i,1,n){
	v.pb(a[i]-a[i-1]);
}
ll lt  =0 ,rt = 0;
k =(ll)v.siz;
// ws(v);
fr(i,1,k){
	if(i > rt){
		lt = i; rt = i;
		while(rt<k && v[rt-lt] == v[rt]){
			rt++;
		}
		z[i] = rt-lt;
		rt--;
	}
	else{
		ind = i-lt;
		if(z[ind] < rt-i+1)
			z[i] =z[ind];
		else{
			lt = i;
			while(rt<k && v[rt-lt] == v[rt]){
				rt++;
			}
			z[i] = rt-lt;
			rt--;
		}
	}
	 // ws(z[i]);

}
fr(i,1,k){
	if(z[i] == m-1 )
		ans++;
}
cout<<ans;
return 0 ;
}
