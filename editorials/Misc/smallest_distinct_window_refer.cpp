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
ll mrk[30] ;
string s;
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>t;
while(t--){
	cin>>s;
	memset(mrk,0,sizeof(mrk));
	fr(i,0,sz(s)){
		mrk[s[i]-'a'] = 1; 
	}
	cnt = 0 ;
	fr(i,0,27){
		cnt += mrk[i];
		mrk[i] = 0 ;
	}
	j = 0 ; i = 0 ; x = 0;
	ans = sz(s) ;
	while( j < sz(s)){

		while(j < sz(s) && x < cnt ){
			if(mrk[s[j] -'a'] == 0 ){
				x++;
			}
			mrk[s[j]-'a']++ ;
			j++;
		}
		while(i < j && x >= cnt ){
			ans = min(ans , j - i ) ; 
			mrk[s[i] -'a']--;
			if(mrk[s[i]-'a'] == 0 ) x--;
			i++;
		}
		
	}
	cout<<ans<<"\n";

}



return 0 ;
}