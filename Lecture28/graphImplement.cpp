#include <iostream>
#include <list>
#include <unordered_map>
#include <cstring>
using namespace std;

template<typename T>
class Graph {
    unordered_map< T,list<pair<T,int>> > adjList;
public:
    Graph() {
    }
    void addEdge (T u, T v, int value, bool biDirctn = true) {
        adjList[u].push_back(make_pair(v,value));
        if (biDirctn){
            adjList[v].push_back(make_pair(u,value));
        }
    }
    void print() {
        for(auto it:adjList) {
            T vertex = it.first;
            cout << vertex;
            for (auto neighbr : it.second) {
                cout << "-->" << neighbr.first << "(" << neighbr.second << ")";
            }
            cout << endl;
        }
    }
    bool isCyclicBFS(T src){
		queue<T> q;
		map<T,bool> visited;

		map<T,T> parent;

		q.push(src);
		visited[src] = true;
		parent[src] = src;

		while(!q.empty()){
            
			T temp = q.front();

			q.pop();

			for(auto neighbour:adjList[temp]){
				if(visited[neighbour] && parent[temp] != neighbour){
					return true;
				}
                else if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour] = true;
					parent[neighbour] = temp;
				}
			}
		}
		return false;
	}
};

int main() {
    Graph<string> g;
    g.addEdge("1", "3", 10, false);
    g.addEdge("1", "2", 20,  false);
    g.addEdge("1", "4", 30, false);
    g.addEdge("2", "1", 50, false);
    g.addEdge("2", "5", 80,  false);
    g.addEdge("5", "3", 100, false);
    g.addEdge("4", "5", 20, false);
    g.print();
    return 0;
}