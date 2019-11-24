#include <bits/stdc++.h>
#include <list>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;


class Graph
{	unordered_map<int, list< pair<int,int> > > adjList;
	
	int V;
public:
	Graph(int v){
		V= v;
	}

	void addEdge(int u, int v, int weight, bool bidir = true ){
		adjList[u].push_back(make_pair(v,weight));

		if (bidir)
		{
			adjList[v].push_back(make_pair(u,weight));
		}
	}

	void prims( ){

		unordered_map<int, int> visited;

		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q; //pair<weight, vertex>
		int totalweight =0;
		q.push(make_pair(0,0));

		while(!q.empty()){
			pair<int, int > top =  q.top();
            if(visited.count(top.second) != 0){
            	q.pop();
                continue;
            }
			
			totalweight+= top.first;
            visited[top.second] = true;
			//cout<<top.second<<" "<<totalweight<<endl; 
            q.pop();
			for(auto neighbour : adjList[top.second]){
					//cout<<neighbour.first<<endl;
					q.push(make_pair(neighbour.second, neighbour.first));

			}
        }
            cout<<totalweight<<endl;
	}





	void printGraph(){
		for (auto it:adjList)
		{
			int vertex = it.first;
			cout<< vertex<<"==";
			for(auto neighbour: it.second){
				cout<<neighbour.first<<"-"<<neighbour.second<<" --> ";
			}
			cout<<endl;
		}
	}

};

int main(int argc, char const *argv[])
{
	int V = 10;
	Graph g(V);

	g.addEdge(0,1,20);
	g.addEdge(1,2,10);
	g.addEdge(1,3,5);
	g.addEdge(4,3,20);
	g.addEdge(2,7,15);
	g.addEdge(7,5,13);
	g.addEdge(7,8,3);
	g.addEdge(7,9,12);
	g.addEdge(6,5,30);
	g.addEdge(6,9,5);

	g.printGraph();
	g.prims();


	return 0;
}






