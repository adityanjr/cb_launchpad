#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

typedef double dbl;
typedef float flt;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define eps 1e-9
#define inf 1000000000
#define infll 1000000000000000000LL
#define abs(x) ((x)<0?-(x):(x))
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define px first
#define py second
#define sz(x) ((int)(x).size())
#define intclz(x) __builtin_clz(x)
#define intctz(x) __builtin_ctz(x)
#define intln(x) (32-intclz(x))
#define intbc(x) __builtin_popcount(x)
#define llclz(x) __builtin_clzll(x)
#define llctz(x) __builtin_ctzll(x)
#define llln(x) (64-llclz(x))
#define llbc(x) __builtin_popcountll(x)
#define atbit(x,i) (((x)>>(i))&1)
#define tof(x) __typeof(x)
#define FORab(i,a,b) for (int i=(a); i<=(b); ++i)
#define RFORab(i,a,b) for (int i=(a); i>=(b); --i)
#define FOR1(i,n) FORab(i,1,(n))
#define RFOR1(i,n) RFORab(i,(n),1)
#define FOR(i,n) FORab(i,0,(n)-1)
#define RFOR(i,n) RFORab(i,(n)-1,0)
#define allstl(i,x,t) for (t::iterator i = (x).begin(); i!=(x).end(); ++i)
#define rallstl(i,x,t) for (t::reverse_iterator i = (x).rbegin(); i!=(x).rend(); ++i)
#define begend(x) (x).begin(),(x).end()
#define ms(a,v) memset(a,v,sizeof(a))
#define msn(a,v,n) memset(a,v,n*sizeof(a[0]))
#define mcp(d,s,n) memcpy(d,s,n*sizeof(s[0]))
#define clamp(x,a,b) min(max(x,a),b)
#define endl '\n'

typedef pair<ll,int> pli;

pli sol(int at, int mask, vi& a, vi& m, vector<map<int,pli> >& dp) {
	if (at == -1) return pli(0,0);
	if (dp[at].find(mask) != dp[at].end()) return dp[at][mask];
	pli notake = sol(at-1, mask, a, m, dp);
	if (mask & m[at]) {
		dp[at][mask] = notake;
		return notake;
	}
	pli take = sol(at-1, mask | m[at], a, m, dp);
	take.first += a[at];
	take.second += 1;
	pli good = notake;
	if (take.first > good.first) good = take;
	else if (take.first == good.first) good.second = max(good.second, take.second);
	dp[at][mask] = good;
	return good;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("in2.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);

	int n;
	while (cin>>n) {
		vi a(n), m(n);
		FOR(i,n) {
			cin>>a[i];
			int x = a[i], xd = 0;
			while (x) {
				xd |= 1<<(x%10);
				x /= 10;
			}
			m[i] = xd;
		}
		vector<map<int,pli> > dp(n);
		pli good = sol(n-1, 0, a, m, dp);
		cout<<good.second<<endl;
	}

	return 0;
}
