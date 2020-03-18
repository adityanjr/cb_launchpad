#include <bits/stdc++.h>
using namespace std;
#define ll long long


template<typename T>
class Graph{
    map <T, list<pair<T,int> > > adjList;

public:
    Graph(){
    }
    void addEdge(T u, T v, int w, bool bidir = true){
        adjList[u].push_back(make_pair(v,w));
        if(bidir) adjList[v].push_back(make_pair(u,w));
    }

    void print(){
        for(auto i : adjList){
            cout << i.first <<"->";

            for(auto entry : i.second){
                cout<<"(" << entry.first << "," << entry.second <<") " ;
            }

            cout << endl ;
        }
    }

    void dijkstra(T src, int ver){

        unordered_map<T, int> dist;
        set <pair<int,T>> s;

        for(auto j : adjList){
            dist[j.first] = INT_MAX;
        }

        dist[src] = 0;
        s.insert(make_pair(0,src));

        while(!s.empty()){
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            for(auto chilPair : adjList[node]){
                if(nodeDist + chilPair.second < dist[chilPair.first]){
                    T dest = chilPair.first;
                    auto f = s.find( make_pair(dist[dest],dest));
                    if(f != s.end()){
                        s.erase(f);
                    }
                    dist[dest] = nodeDist + chilPair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        for(int i=1; i<=ver; i++){
            if (i==src) continue;
            else if(dist[i] == INT_MAX) cout << "-1 ";
            else cout << dist[i] << " ";
        }
    }
};

int main(){
    int t; cin>>t;
    for(int u=0; u<t; u++){

        int ver,edge;
        cin>>ver>>edge;

        Graph<int> g;

        for(int i=0; i<edge; i++){
            int u,v,r;
            cin>>u>>v>>r;
            g.addEdge(u,v,r);
        }
        int src;
        cin >> src;
        g.dijkstra(src,ver);
        cout<<endl;
    }
}