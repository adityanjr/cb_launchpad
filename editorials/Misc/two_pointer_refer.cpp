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
#define N 1504

const long long infl = 1e8+5;

int n,m,k,q,x,y,mx =-1,mn=infl,f,val,sz,sm,cnt,t=1,i,j,ind=-1;
int  a[N] ,ans ; 

// ll gives TLE


// ans[27][N];
string s;
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n;
cin>>s;

// fr(k,0,26){
// 	fr(i,0,n){
// 		cnt =0 ;
// 		fr(j,i,n){
// 			if(s[j]-'a' != k) cnt++;

// 			ans[k][cnt] = max(ans[k][cnt] , j-i+1);
// 		}
// 	}

// 	fr(i,1,n+1)
// 		ans[k][i] = max(ans[k][i], ans[k][i-1]);
// }

cin>>q;
char ch  ;
int l ;
fr(k,0,q){
	cin>>x>>ch;
	ans = 0 ;
	cnt = 0 ;
	// y = ch- 'a';
	// cout<<ans[y][x]<<"\n";
	 l = 0 ; // left pointer  
	fr(j,0,n){

		if(s[j] != ch )
			cnt++;

		while(l < n && cnt > x) {
			if(s[l] != ch) --cnt;
			l++;
		}

		ans = max(ans , j-l+1);

	}
	cout<<ans<<"\n";
}


return 0 ;
}