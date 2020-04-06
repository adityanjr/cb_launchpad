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
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define siz size()
#define N 1000004
const long long infl = 1e18+5;

ll m,n,p,q,x,y ,cn,k,tmp1,tmp,mx =0 ,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind = -1,ci;
ll z[N] ;
string s;

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>s;
ll l = 0 ,r = 0 ;
n = (ll)s.siz;
fr(i,1,n){
	if(i > r){
		l = i;
		r =i;
		while(r< n && s[r-l] == s[r] ) r++;
		z[i] = r-l;
		r--;

	}
	else{
		k= i- l; 
		if(z[k] < r-i+1){
			z[i] = z[k];
		}
		else
		{
			l = i; 
			while(r< n && s[r-l] == s[r] ) r++;
			z[i] = r-l;
			r--;

		}
	}
	// ws(z[i]);
	
} 
ind  =-1;
fr(i,1,n){
	if(z[i] + i == n ){
		if(mx >= z[i]){
			ind = i; 
			break;
		}
	}
	mx = max(mx ,z[i]);
		
}

if(ind == -1 ){
	cout<<"Just a legend";
	return 0;
}
fr(i,ind,n)
	cout<<s[i];
return 0 ;
}
