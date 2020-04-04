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
#define N 300004
const long long infl = 1e18+5;

ll m,n,p,q,x,y ,cn,k,tmp1,tmp,mx =-1 ,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind = -1,ci;
ll a[N],tree[21][N],lazy[21][N],dp[21] ;

void build(int node ,int start ,int end , int ind){
	if(start == end){

		tree[ind][node] = 0;

		if( (a[start] & (1LL<<ind) )!= 0 ){
			tree[ind][node] = 1;
		}
		return;
	}

	int mid = (start+end)>>1;
	build(2*node,start,mid,ind);
	build(2*node+1,mid+1,end,ind);
	tree[ind][node] = tree[ind][2*node] + tree[ind][2*node+1];
	return;

}

void update(int node,int start ,int end , int  l ,int r ,int ind){

	if(lazy[ind][node] != 0 ){
		tree[ind][node] = (end-start+1) -tree[ind][node];
		if(start != end){
			lazy[ind][2*node] ^= 1;
			lazy[ind][2*node+1] ^=1;

		}
		lazy[ind][node] = 0;
	}

	if(start>end || start > r || end < l)
		return ;

	if(start>= l && end <= r){
		tree[ind][node] = (end-start+1) -tree[ind][node];
		if(start != end){
			lazy[ind][2*node] ^= 1;
			lazy[ind][2*node+1] ^=1;

		}
		lazy[ind][node] = 0;
		return ;
	}

	int mid = (start+end)>>1;
	update(2*node,start,mid,l,r,ind);
	update(2*node+1,mid+1,end,l,r,ind);
	tree[ind][node] = tree[ind][2*node] + tree[ind][2*node+1];
	return;

}

ll query(int node,int start ,int end , int  l ,int r ,int ind){

	if(lazy[ind][node] != 0 ){
		tree[ind][node] = (end-start+1) -tree[ind][node];
		if(start != end){
			lazy[ind][2*node] ^= 1;
			lazy[ind][2*node+1] ^=1;

		}
		lazy[ind][node] = 0;
	}

	if(start>end || start > r || end < l)
		return 0 ;
	if(start>= l && end <= r){
		return tree[ind][node];
	}
		int mid = (start+end)>>1;
	return (query(2*node,start,mid,l,r,ind) + query(2*node+1,mid+1,end,l,r,ind) ) ;




}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n;
fr(i,0,n){
	cin>>a[i];
}
dp[0]=1;
fr(i,1,21){
	dp[i] = 2LL*dp[i-1];
}
fr(i,0,21){
	build(1,0,n-1,i);
}
cin>>m;
fr(i,0,m){
	cin>>k;
	if(k==2){
		cin>>p>>q>>x;
		fr(j,0,21){
			if(x& (1LL<<j)){
				update(1,0,n-1,p-1,q-1,j);
			}
		}
	}
	else{
		cin>>p>>q;
		sm = 0;
		fr(j,0,21){
			sm += (query(1,0,n-1,p-1,q-1,j) * (dp[j]) );

		}
		cout<<sm<<"\n";
	}
}
return 0 ;
}
