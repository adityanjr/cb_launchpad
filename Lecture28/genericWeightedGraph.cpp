#include <iostream>
#include <list>
#include <unordered_map>
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
	g.addEdge("1","4",5,false);
	g.addEdge("1","3",false);
	g.addEdge("1","2",10,false);
	g.addEdge("2","1",false);
	g.addEdge("2","5",16,false);
	g.addEdge("5","3",19,false);
	g.addEdge("4","5",false);
	g.printGraph();


	return 0;
}






