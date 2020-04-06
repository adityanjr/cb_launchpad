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
#define N 9

const long long infl = 1e18+5;

ll n,m,k,q,x,y,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1;
ll a[N][N] ;
int check_row(int b[N], int k ){
	int i ; 
	fr(i,0,N) if(b[i] == k) return 0 ; 
	return 1;
}
int check_grid(int b[N][N] ,int x ,int y, int p ,int q ,int k ){
	int i , j  ;
	fr(i,x,p+1){
		fr(j,y,q+1){
			if(b[i][j] == k ) return 0 ;
		}
	}
	return 1;
}

int dfs(int b[N][N]){

	int i ,j,k ,rb[N][N] ,f  = 1;
	fr(i,0,N){
			fr(j,0,N){
		rb[j][i] = b[i][j];
		// cout<<b[i][j]<<" ";
	}
	// cout<<endl;
	}
	// cout<<endl;


	fr(i,0,N){
		int cl[N];
		fr(j,0,N){
			if(b[i][j] != 0 ) continue ;
			f = 0 ;
			fr(k,1,10){
				if(check_row(b[i],k) + check_row(rb[j],k) + check_grid(b , 3 * (i/3) , 3*(j/3) ,3* (i/3 )+ 2 , 3*(j/3) +2 , k ) < 3 ) continue ;
				b[i][j] = k ; 
				int re = dfs(b);
				if(re == 1){
					a[i][j] = k ;
					// ws(re);
					return 1;	
				} 
				b[i][j] = 0 ;
			}
			if(b[i][j] == 0 ) return 0 ; 
		}
	}
	return f ; 

}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>t;
while(t--){
	int b[N][N];
	fr(i,0,N)
		fr(j,0,N){
			cin>>a[i][j];
			b[i][j] = a[i][j];
		}

	dfs(b);
	fr(i,0,N){
		fr(j,0,N){
			cout<<a[i][j]<<" ";
		}
		// cout<<" ";
	}
	cout<<"\n";
}



return 0 ;
}