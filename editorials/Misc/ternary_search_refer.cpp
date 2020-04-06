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
const long long infl = 1e16+5;

ll m,n,p,q,x,y ,cn,k,tmp1,tmp,mx =-1 ,mn=infl,f,val,sz,cnt,aans=infl,t=1,ind = -1,ci;

std::vector<ll> a(N),b(N);
ll fn(ll v){

  ll i,j,sm= 0;
  fr(i,0,n){
    if(a[i]>= v)
      break;
    sm += v-a[i];

  }
  fr(i,0,m){
    if(b[i] <= v)
      break;
    sm += b[i] -v;
  }
  return sm;

}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
ll i, j;
cin>>n>>m;
a.resize(n);
b.resize(m);
fr(i,0,n)
  cin>>a[i];
fr(i,0,m)
  cin>>b[i];

sort(all(a));
sort(all(b),greater<ll>());
ll low = 0 ,high = 1234567890 , mid ,mid2,ans = infl,v1,v2;

while(low <= high){
  mid = low + (high -low)/2;
  v1 = fn(mid);
  v2 = fn(mid+1);
  if(v1 > v2){
    low = mid+1;
  }
  else{
    sz = mid+1;
    high = mid-1;
  }
  ans = min(ans, min(v1,v2));

}
// ws(sz);
// fr(i,0,100){
//   mid1 = low + (high-low)/3;
//   mid2 = high - (high-low)/3;
//   v1 = fn(mid1);
//   v2 = fn(mid2);
//   if(v1 >= v2 ){
//     low = mid1;
//   }
//   else
//     high = mid2;
//   ans = min(ans , min(v1,v2));

// }
// ws(high);
cout<<ans;
return 0 ;
}
