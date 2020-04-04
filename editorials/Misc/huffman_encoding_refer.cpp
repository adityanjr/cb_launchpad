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

ll n,k,q,x,y,mx =-1,mn=infl,f,val,sz,sm,ans,t=1,i,j,ind=-1;
string s ; 
ll cnt[30];
class mytype
{
public:
	mytype(char c1 ,int f,  mytype  *l1 ,mytype *r1 );
	char c ;
	mytype *l ,*r  ;
	int f ;
	
};
mytype::mytype(char c1 ,int f1 ,  mytype  *l1 ,mytype *r1 ){
	c = c1;	f= f1; l = l1; r = r1;
}

struct cmp
{
	bool operator()( mytype *a , mytype  *b ){
		return a->f > b->f ;
	}
};
// std::map<mytype, mytype ,cmp> mp;

void rec(mytype *m ,string str ){
	if(m->c != '.'){
		cout<<str<<" ";
		return;
	}
	rec(m->l, str + "0");
	rec(m->r,str+"1");
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>sz;
while(sz--){
	priority_queue<mytype* , std::vector<mytype*> ,cmp > pq;

	cin>>s;
	fr(i,0,sz(s))
		cin>>cnt[s[i]-'a'];
	fr(i,0,sz(s)){
		// mp[m] = m ;
		pq.push(new mytype(s[i], cnt[s[i]-'a'],NULL, NULL ));
	}
	while(sz(pq) > 1){
		mytype *m1 = pq.top(); pq.pop();
		mytype *m2 = pq.top(); pq.pop();
		// mp[t-1] = m ;
		pq.push(new mytype ('.',m1->f + m2->f ,m1 , m2) );

	}
	mytype *m = pq.top();
	rec(m,"") ; 
	cout<<"\n";
}



return 0 ;
}