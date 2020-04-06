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
#define N 12

const long long infl = 1e18+5;

ll n,m,k,q,x,y,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1;
void pp(int a[N][N]){
	int i ,j ; 
	fr(i,0,n){
		fr(j,0,n) 
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}

void print_my(int a[N][N]){
	f =1;
	// pp(a);cout<<"..\n";

	std::vector<int> v;
	int i,j;
	fr(i,0,n){
		fr(j,0,n){
			if(a[j][i] == 1)
			v.pb(j+1);
		}
	}
	cout<<"[";
	fr(i,0,sz(v))
		cout<<v[i]<<" ";
	cout<<"]";

}

int checkd(int a[N][N] , int r ,int c  , int xc  ,int yc){
	int i = r ; j = c ; 

	while(i < n && j < n && i >= 0 && j >= 0  )
	{
		if(a[i][j] == 1) return 0 ; 
		i += xc;
		j += yc;
	}
	return 1;
}
int check(int a[N][N] ,int r ,int c){

	int i ,j ; 
	fr(i,0,n) if(a[r][i] == 1) return 0 ;
	fr(i,0,n) if(a[i][c] == 1 ) return 0 ;

	if(checkd(a,r,c,1,1) == 0 ) return 0  ;
	if(checkd(a,r,c,1,-1) == 0 ) return 0; 
	if(checkd(a,r,c,-1,1) == 0 ) return 0 ; 
	if(checkd(a,r,c,-1,-1) == 0 ) return 0; 

	return 1;
}
void dfs(int a[N][N] , int r , int c ){
	if(c == n){
		print_my(a);
		return ; 
	}
	if(check(a, r,c) == 0) return ;
	a[r][c] = 1;
	int i ; 
	// pp(a);
	// print_my(a);
	fr(i,0,n){
		dfs(a,i,c+1);
		if(c == n - 1 ) break ;
	}

	a[r][c] = 0 ; 
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>t;
while(t--){
	cin>>n;
	f = 0 ; 
	int a[N][N] ;
	memset(a,0,sizeof(a));
	fr(i,0,n) {
		// pp(a); 
		dfs(a,i,0);
	}
	if(f == 0 ) cout<<"-1";
	cout<<"\n";
}



return 0 ;
}