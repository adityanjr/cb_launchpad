#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;


class Graph
{	unordered_map<int, list<int> > adjList;
public:
	int V;
	Graph(int v){
		V= v;
	}

	void addEdge(int u, int v, bool bidir = true ){
		adjList[u].push_back(v);

		if (bidir)
		{
			adjList[v].push_back(u);
		}
	}


	void dfsHelper(int i, bool visited[], int &countrySize){
		visited[i] = true;
		countrySize++;

		for (auto neighbour: adjList[i])
		{
			if(!visited[neighbour]){
				dfsHelper(neighbour, visited, countrySize);
			}
		}
	}


	int moon(){
		bool* visited = new bool[V]; 

		for (int i = 0; i < V; ++i)
		{
			visited[i] = false;
		}

		int totalWays = (V*(V-1))/2;


		for (int i = 0; i < V; ++i)
		{
			if(!visited[i]){
				int countrySize =0;
				dfsHelper(i, visited, countrySize);
				totalWays -= countrySize*(countrySize-1)/2;
			}
		}
		return totalWays;
	}



	void printGraph(){
		for (auto it:adjList)
		{
			int vertex = it.first;
			cout<< vertex<<"==";
			for(auto neighbour: it.second){
				cout<<neighbour<<" --> ";
			}
			cout<<endl;
		}
	}

};

int main(int argc, char const *argv[])
{
	int V, n;
	cin>>V>>n;

	Graph g(V);
	for (int i = 0; i < n; ++i)
	{	int u,v;
		cin>>u>>v;
		g.addEdge(u,v);
	}
	
	g.printGraph();

	cout<<g.moon()<<endl;

	return 0;
}






