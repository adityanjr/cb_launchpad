#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;


class Graph
{	unordered_map<string, list<string> > adjList;
public:
	Graph(){
	}

	void addEdge(string u, string v, bool bidir = true ){
		adjList[u].push_back(v);

		if (bidir)
		{
			adjList[v].push_back(u);
		}
	}
	void printGraph(){
		for (auto it:adjList)
		{
			string vertex = it.first;
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
	
	Graph g;
	g.addEdge("1","4",false);
	g.addEdge("1","3",false);
	g.addEdge("1","2",false);
	g.addEdge("2","1",false);
	g.addEdge("2","5",false);
	g.addEdge("5","3",false);
	g.addEdge("4","5",false);
	g.printGraph();


	return 0;
}






