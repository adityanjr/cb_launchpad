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
#define sz(x)  (ll)x.size()
#define N 1000004

const long long infl = 1e18+5;

ll n,m,k,q,x,y,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1;
ll a[N] ;
multiset<ll>s;
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n;
fr(i,0,n) cin>>a[i];
s.insert(a[0]);
fr(i,1,n){
	val = (ll) *s.rbegin();
	if(a[i] >= val )
		s.insert(a[i]);
	else{
		s.erase(s.lower_bound(a[i] + 1 ));
		s.insert(a[i]);
	}
// ws(sz(s));
// ws(s);
}
cout<<sz(s);



return 0 ;
}