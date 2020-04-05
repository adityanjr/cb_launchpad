#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
using namespace std;

int mark[1000003];
vector<int> prime;
int a[110];
vector<int> odd;
vector<int> even;
int val[110];
int isprime[110];
int N, M;
int maxflow = 0;
int S = 108, T = 109;
int cap[110][110];
int flow[110][110];
vector<int> adj[110];
int path[110];
int INF = 123456;
void sieve(){
    for(int i=2;i*i<=1000000;++i){
        if(mark[i]) continue;
        for(int j=i;j<=1000000/i;++j){
            mark[i*j] = 1;
        }
    }
    for(int i=2;i<=1000000;++i){
        if(!mark[i]) prime.push_back(i);
    }
}

int augment(int v, int mf){
    if(v == S){
        maxflow += mf;
        return mf;
    }
    int u = path[v];
    bool backflow = false;
    if(flow[v][u] > 0) backflow = true;
    if(backflow){
        mf = min(mf, flow[v][u]);
    } else {
        mf = min(mf, cap[u][v] - flow[u][v]);
    }
    mf = augment(u, mf);
    if(backflow){
        flow[v][u] -= mf;
    } else {
        flow[u][v] += mf;
    }
    return mf;
}

void edmondskarp(){
    while(true){
        queue<int> q;
        memset(path, -1, sizeof path);
        q.push(S);
        path[S] = S;
        bool augmented = false;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i=0;i<adj[u].size();++i){
                int v = adj[u][i];
                if(path[v] != -1) continue;
                if(cap[u][v] - flow[u][v] > 0 || 
                   flow[v][u] > 0){
                    path[v] = u;
                    if(v == T){
                        augment(T, INF);
                        augmented = true;
                        break;
                    } else {
                        q.push(v);
                    }
                }
            }
            if(augmented) break;
        }
        if(!augmented) break;
    }
}

void solve_maxflow(){
    for(int j=0;j<M;++j){
        int u = odd[j];
        int v = even[j];
        cap[u][v] = min(val[u],val[v]);
        cap[S][u] = val[u];
        cap[v][T] = val[v];
    }
    for(int i=0;i<110;++i)
        for(int j=0;j<110;++j)
            flow[i][j]=0;
    
    edmondskarp();
}

int main(){

if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
    sieve();
    scanf("%d%d", &N,&M);
    for(int i=0;i<N;++i){
        scanf("%d", &a[i]);
    }
    int u,v;
    for(int i=0;i<M;++i){
        scanf("%d%d", &u,&v);
        --u; --v;
        if(u%2==0) swap(u,v);
        odd.push_back(u);
        even.push_back(v);
    }
    for(int i=0;i<M;++i){
        adj[S].push_back(odd[i]);
        adj[odd[i]].push_back(S);
        adj[odd[i]].push_back(even[i]);
        adj[even[i]].push_back(odd[i]);
        adj[even[i]].push_back(T);
        adj[T].push_back(even[i]);
        cap[even[i]][T] = INF;
        cap[S][odd[i]] = INF;
    }
    maxflow = 0;
    memset(isprime, 1, sizeof isprime);
    for(int k=0;k<prime.size();++k){
        memset(val, 0, sizeof val);
        bool ok = false;
        for(int j=0;j<N;++j){
            int tmp = a[j];
            int cnt = 0;
            while(tmp && (tmp%prime[k]) == 0){
                tmp /= prime[k];
                ++cnt;
            }
            val[j] = cnt;
            if(cnt) {
                isprime[j] = 0;
                ok = true;
            }
        }
        if(!ok)continue;
        solve_maxflow();
    }
    vector<int> extra;
    for(int i=0;i<N;++i){
        bool ok = true;
        if(!isprime[i] || a[i] == 1) continue;
        for(int j=0;j<extra.size();++j){
            if(extra[j] == a[i]){
                ok = false;
                break;
            }
        }
        if(!ok) continue;
        ok = false;
        memset(val, 0, sizeof val);
        extra.push_back(a[i]);
        for(int j=0;j<N;++j){
            int tmp = a[j];
            int cnt = 0;
            while(tmp && (tmp%a[i])==0){
                ++cnt;
                tmp /= a[i];
            }
            if(cnt){
                val[j] = cnt;
                ok = true;
            }
            // cout<<cnt<<" ";
        }
        if(!ok) continue;
        solve_maxflow();
    }
    printf("%d\n", maxflow);
    return 0;
}