#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

template<typename T>
class Graph
{	unordered_map<T, list< pair<T,int> > > adjList;
public:
	Graph(){
	}

	void addEdge(T u, T v, int weight, bool bidir = true ){
		adjList[u].push_back(make_pair(v,weight));

		if (bidir)
		{
			adjList[v].push_back(make_pair(u,weight));
		}
	}

	void dfsHelper(T src,unordered_map<T,bool> &visited){

		cout<<src<<"-->";
		visited[src] = true;
		for (auto neighbour: adjList[src])
		{
			if(!visited[neighbour.first]){
				dfsHelper(neighbour.first, visited);
			}
		}

	}

	void dfsTraversal(T src){
		unordered_map<T,bool> visited;
		dfsHelper(src, visited);
	}

	void printGraph(){
		for (auto it:adjList)
		{
			T vertex = it.first;
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
	
	Graph<string> g;
	g.addEdge("A","B",5);
	g.addEdge("B","D",10);
	g.addEdge("B","E",10);
	g.addEdge("D","C",0);
	g.addEdge("A","C",16);

	g.printGraph();
	g.dfsTraversal("A");


	return 0;
}






