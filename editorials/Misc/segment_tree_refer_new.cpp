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

const long long infl = 1e6+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans,mn = infl ;
ll a[N] ;
struct my_node
{
	int mx = -infl;
	int lazy =0  ; 
	my_node(){}
};

struct seg_tree{
	int n ;
	vector< my_node > tree; 
	vector< int > temp ; 
	seg_tree(vector < int > &v ){
		n = v.size();
		temp = v ;
		tree.assign(4*(n+1) , my_node()) ;
		build(1,n,1) ; 
	}
	void build(int l ,int r ,int my_node){
		if(l == r ){
			tree[my_node].mx = temp[l-1];
			return ; 
		}
		int mid  = (l+r) / 2 ; 
		build(l,mid,2*my_node);
		build(mid+1,r,2*my_node+1);
		update(my_node);
	}

	bool can(int num ){
		if(num > n  ) return false ; 
		int k = get_value(num) ; 
		if(k == 0 ) return false ; 
		int ind1 = get_rightmost(k) ; 
		int ind2 = get_rightmost(k+1) ; 
		int rem = num - ind2 ; 
		lazy_update(1,ind2,-1);
		lazy_update(ind1  -rem + 1 , ind1,-1)  ;
		// DebugTree();
		// cout<<"\n";
		return true ; 
	}

	int get_value(int num){
		return get_value(1,n,1,num) ; 
	}
	int get_value(int l ,int r ,int node , int num){
		if(num < l || num > r ) return -infl;
		if(l == r) return tree[node].mx; 
		int mid  = (l+r)/2;
		propogate_lazy(node);
		return max( get_value(l,mid,2*node,num) , get_value(mid+1,r,2*node+1,num));
	}

	int get_rightmost(int value){
		if(tree[1].mx < value ) return 0 ;
		return get_rightmost(1,n,1,value) ; 
	}
	
	int get_rightmost(int l ,int r ,int node,int value){
		if(l == r) return l ;
		propogate_lazy(node); 
		int mid = (l+r)/2;
		if(tree[2*node+1].mx >= value){
			return get_rightmost(mid+1,r,2*node+1,value) ;
		}
		else{
			return get_rightmost(l,mid,2*node,value) ; 
		}
	}

	void update(int my_node){
		propogate_lazy(my_node) ; 
		tree[my_node].mx = max(tree[2*my_node].mx , tree[2*my_node+1].mx) ; 
	}

	void propogate_lazy(int my_node){
		int v = tree[my_node].lazy; 
		tree[2*my_node].mx += tree[my_node].lazy ; 
		tree[2*my_node+1].mx += tree[my_node].lazy;
		tree[2*my_node].lazy +=tree[my_node].lazy ;
		tree[2*my_node+1].lazy += tree[my_node].lazy;
		tree[my_node].lazy = 0 ; 
	}

	void lazy_update(int l ,int r ,int value) {
		if( l > r ) return ; 
		lazy_update(1,n,1,l,r,value) ;
	}

	void lazy_update(int l, int r , int my_node , int c1 ,int c2 , int value){
		if( l >= c1 && r <= c2){
			tree[my_node].mx += value ; 
			tree[my_node].lazy += value ; 
			if(l == r)  temp[l - 1] = tree[my_node].mx; 

			return ; 
		}
		if( l> c2 || r < c1 ) return ; 
		int mid = (l+r) / 2;
		lazy_update(l,mid,2*my_node,c1,c2,value) ; 
		lazy_update(mid+1,r,2*my_node+1,c1,c2,value);
		update(my_node) ; 
	}

	 void DebugTree() {
        DebugTree(1, 1, n);
	    }

    void DebugTree(int my_node, int left, int right) {
        if (left == right) {
            cout<< tree[my_node].mx << ' ';
            return;
        }

        propogate_lazy(my_node);
        int mid = (left + right) / 2;
        DebugTree(2 * my_node, left, mid);
        DebugTree(2 * my_node + 1, mid + 1, right);
    }


};

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

vector<int> v;
cin>>n>>m;
fr(i,0,n){
	cin>>x;
	v.pb(x); 
}
sort(all(v));
reverse(all(v));
seg_tree st(v);

fr(i,0,m){
	cin>>x;
	if(st.can(x) == false ){
		cout<<i;
		return 0 ;
	}
}

cout<<m;
return 0 ;
}