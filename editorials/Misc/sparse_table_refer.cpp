// avvinci
// #include"prettyprint.hpp"
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
#define N 300004
const long long infl = 1e15+5;

ll mm,n,p,q,x,y ,cn,kk,tmp1,tmp,mx =0 ,mnn,f,val,sz,sm,cnt,anns,t=1,ii,jj,ind = -1,ci;

ll m[N][20] ,a[N] ,mn[N][20];
vector<int>  ve;

int is (int i ,int j ){
	int k = floor(log2(j-i+1));
	int v1 = min(mn[i][k], mn[j-(1<<k)+1][k]);
	int v2   = __gcd(m[i][k], m[j-(1<<k)+1][k]);

	if (v1 == v2){
	// 	if(f)
	// 	ws(v1);
	// 	ws(v2);
	// 	ws(k);
	// ws(i);
	// ws(j);
	return 1;
	}	

	return 0 ;

}

int ok(int mid){
	int i = 0 ;
	fr(i,0,n-mid+1){
		if(is(i,i+mid-1)){
			return 1;
		}
	}
return 0 ;
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
int i,j;
fr(i,0,N){
	fr(j,0,20){
		mn[i][j] = INT_MAX;
		m[i][j] = -1;
	}
}
cin>>n;
fr(i,0,n) {
	cin>>a[i];
	m[i][0] = a[i];
	mn[i][0] = a[i];

	// cout<<a[i]%1470<<"\n";
}

for(j = 1; 1<<j <= n ; j++ ){
	for(i =0 ;i + (1<<j) -1 < n ;i++){
		if(m[i][j-1] == -1 || m[i+ (1<<(j-1))][j-1] == -1) continue;
		m[i][j] = __gcd(m[i][j-1],m[i+ (1<<(j-1))][j-1]);
		mn[i][j] = min(mn[i][j-1],mn[i+ (1<<(j-1))][j-1]);
		
	}
}
  // ws(m[26][44]);
int low = 1 , high  = n +1,mid,ans =-1;
while(low<= high){
	mid = low + (high -low) /2;
	if(ok(mid)){
		ans = mid;
		low =mid + 1;
	}
	else{
		high = mid - 1;
	}
}
f = 1;
mid =ans;
fr(i,0,n-mid+1){
	if(is(i,i+mid-1)){
		ve.pb(i);
	}
}
cout<<ve.siz<<" "<<ans-1<<"\n";
fr(i,0,ve.siz){
	cout<<ve[i]+1<<" ";
}

return 0 ;
}