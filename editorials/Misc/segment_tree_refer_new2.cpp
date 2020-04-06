// avvinci - sem_7 
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

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans,mx = -1,mn = infl ;
ll a[N] ;

struct my_node {
	ll mn  ,mx , is_dec   ,is_inc , sm  ;
	my_node(){}
	my_node(ll a1 ,ll a2,ll a3, ll a4, ll a5){
		mn = a1; mx =a2 ;
		is_dec = a3; is_inc= a4;
		sm = a5;
	}
}  ;

my_node tr[N] ; 

my_node fun(my_node a ,my_node b ){
	my_node nn ; 
	nn.mx  = max(a.mx, b.mx) ;
	nn.mn = min(a.mn,b.mn) ; 
	nn.sm = a.sm + b.sm;
	nn.is_dec = 0 ; nn.is_inc = 0 ;
	if(a.is_dec && b.is_dec && (a.mn >= b.mx))  nn.is_dec = 1 ;
	if(a.is_inc && b.is_inc && (a.mx <= b.mn )) nn.is_inc  = 1 ;
	return  nn; 
}

void build(int node , int l ,int r ){
	if(l == r ){
		ll v = a[l];
		my_node nn(v,v,1,1,v) ;
		tr[node] = nn;
		return ; 
	}
	int mid  =(l+r)/2; 
	build(2*node , l,mid) ;
	build(2*node+1,mid+1,r);
	my_node nn , a = tr[2*node] , b = tr[2*node+1];
	nn = fun(a,b);
	tr[node] = nn ;
}

void update(int node ,int l ,int r , int ind , ll val ){
	if( l == r) {
		my_node nn(val,val,1,1,val) ; 
		tr[node] = nn ; 
		a[ind] = val ; 
		return ; 
	}
	int mid = (l+r)/2 ;
	if(ind >= l && ind <= mid){
		update(2*node , l, mid ,ind ,val) ;
	}
	else{
		update(2*node+1,mid+1,r,ind,val) ;
	}
	my_node nn , a = tr[2*node] , b = tr[2*node+1];
	nn = fun(a,b);
	tr[node] = nn ; 
}

my_node get(int node , int l ,int r , int s ,int e ){
	if( l > e || r < s ){
		my_node nn(infl,-infl,1,1,0 ) ; 
		return nn ;
	}

	if( l >= s && r<= e){
		return tr[node] ;
	}
	int mid  = (l+r)/2 ;
	my_node a , b , nn  ; 
	a = get(2*node,l,mid,s,e) ; 
	b = get(2*node+1,mid+1,r,s,e);
	nn = fun(a,b); 
	return nn ; 
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>n>>q;
fr(i,0,n){
	cin>>a[i];
}
char ch ; 
build(1,0,n-1);
while(q--){
	cin>>ch ;
	if(ch == 'U'){
		cin>>x>>val; x--;
		update(1,0,n-1,x,val);
	}
	else{
		cin>>x>>y; x-- ; y--;
		my_node nn = get(1,0,n-1,x,y) ; 
		if(ch == 'M')
			cout<<nn.mx<<"\n";
		else if(ch =='S')
			cout<<nn.sm<<"\n";
		else if(ch =='I')
			cout<<nn.is_inc<<"\n";
		else{
			cout<<nn.is_dec<<"\n";
		}

	}
}
return 0 ;
}