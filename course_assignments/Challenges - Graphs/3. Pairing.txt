#include <bits/stdc++.h>
using namespace std;
#define ll long long

int binomialCoeff(int n, int k){
    int res = 1;

    if ( k > n - k )
        k = n - k;

    for (int i = 0; i < k; ++i){
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

template<typename T>
class Graph{
    map <T, list<T> > adjList;
public:
    Graph(){
    }

    void addEdge(T u, T v, bool bidir = true){
        adjList[u].push_back(v);
        if(bidir) adjList[v].push_back(u);
    }

    void print(){
        for(auto i : adjList){
            cout << i.first <<"->";

            for(auto entry : i.second){
                cout << entry << ",";
            }
            cout << endl ;
        }
    }

    void dfsHelper(T node, map <T, bool> &visited, int &temp){
        visited[node] = true;
        temp++;

        for(auto neighbour : adjList[node]){
            if(!visited[neighbour]) {
                dfsHelper(neighbour,visited,temp);
            }
        }
    }

    void connectedComponents(int n){
        map <T, bool> visited;
        int ans=0;
        for(auto i :  adjList){
            if(!visited[i.first]){
                int temp=0;
                dfsHelper(i.first,visited,temp);
                ans += binomialCoeff(temp,2);
            }
        }
        cout << binomialCoeff(n,2) - ans <<endl;
    }
};


int main(){
    int n, m;
    cin >> n >>m;
    Graph <int> g;

    for(int i=0; i<m; i++){
        int u,v;
        cin >>u>>v;
        g.addEdge(u,v);
    }
    g.connectedComponents(n);
}