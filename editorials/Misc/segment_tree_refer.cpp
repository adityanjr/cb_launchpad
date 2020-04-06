// avvinci
// march 17 
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
ll a[N] ,tr[N] ;

void build(int node , int start , int end ,int st){
	if(start == end)
		tr[node] = a[start];
	else{
		int mid = start + (end-start)/2;
		build(2*node,start,mid,(st^1));
		build(2*node+1,mid+1,end,(st^1));
		if(st == 0 )
			tr[node] = tr[2*node] ^ tr[2*node + 1];
		else
			tr[node] = tr[2*node] | tr[2*node+1];
	}
}

void update(int node , int start , int end , int ind ,int val,  int st){
	if(start == end)
	{
		a[ind] = val;
		tr[node] = val;
	}
	else{
		int mid = start + (end-start)/2;
		if(ind>=start && ind <= mid){
			update(2*node,start,mid,ind ,val,(st^1));

		}
		else{
			update(2*node+1,mid+1,end,ind ,val, (st^1));
		}

		if(st == 0 )
			tr[node] = tr[2*node] ^ tr[2*node + 1];
		else
			tr[node] = tr[2*node] | tr[2*node+1];

	}

}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>k>>m;
n = 1LL<<k;
fr(i,0, n){
	cin>>a[i];
}
int st;
if(k%2 == 0)
	st = 0 ;
else
	st = 1;
build(1,0,n-1 ,st);
fr(i,0,m){
	cin>>ind>>val;
	update(1,0,n-1,ind-1,val,st);
	cout<<tr[1]<<"\n";

}

return 0 ;
}
