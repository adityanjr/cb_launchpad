#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

    void bfs(T src){
        queue<T> q;
        map<T, bool> visited;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            T node = q.front();
            cout << node <<" " ;
            q.pop();

            for(auto neighbour : adjList[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true ;
                }
            }
        }
    }
    void dfsHelper(T node, map <T, bool> &visited, map <T, T> &parent){
        visited[node] = true;

        for(auto neighbour : adjList[node]){
            if(!visited[neighbour]) {
                parent[neighbour] = node;
                dfsHelper(neighbour,visited,parent);
            }
        }
    }

    void dfs(map <T, T> &parent){
        map <T, bool> visited;
        for(auto i :  adjList){
            T node = i.first;
            if(!visited[node]){
                parent[node] = node;
                dfsHelper(node,visited,parent);
            }
        }
    }

    void beautifulVertices(){
        map <T, T> parent;
        dfs(parent);
        map <T, int> children;
        for(auto i : adjList){
            T node = i.first;
            children[node] = 0;
            for(auto neighbour : adjList[node]){
                if(neighbour != parent[node]) children[node]++;
            }
        }

        int ans = 0;
        for(auto i : adjList){
            T node = i.first;
            if(children[node] > children[parent[node]]) ans++;
        }
        cout<<ans;
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
    g.beautifulVertices();
}