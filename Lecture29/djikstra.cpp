#include <iostream>
#include <list>
#include <set>
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

	void dijkstra(T src){

		set<pair<int, T> > priority;
		unordered_map<T, bool> visited;
		unordered_map<T, int> minDis;
		minDis[src] =0;
		priority.insert(make_pair(0, src));

		while(!priority.empty()){
			pair<int, T> top = *priority.begin();
			T vertex = top.second;
			int dist = top.first;
			priority.erase(top);
			visited[vertex] = true;


			for(auto neighbour: adjList[vertex]){

				if(!visited[neighbour.first]){
					//update 
					if(minDis.count(neighbour.first) ){
						if(minDis[neighbour.first] > (minDis[vertex] + neighbour.second)){
							
							priority.erase(make_pair(minDis[neighbour.first],neighbour.first));
							minDis[neighbour.first] = (minDis[vertex] + neighbour.second);
							priority.insert(make_pair(minDis[neighbour.first],neighbour.first));
						}
					}
					else{
						//insert
						priority.insert(make_pair(neighbour.second, neighbour.first));
						minDis[neighbour.first] = neighbour.second;
					}
				}
			}
		}

		for (auto it = minDis.begin(); it!= minDis.end(); it++)
		{
			cout<<(it->first)<<"-->"<<(it->second)<<endl;
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
	g.addEdge("1","4",3);
	g.addEdge("1","3",7);
	g.addEdge("1","2",5);
	g.addEdge("2","6", 2);
	g.addEdge("1","6", 9);
	g.addEdge("1","9", 10);
	g.addEdge("2","3",1);
	g.addEdge("4","3",5);
	g.addEdge("4","9",3);
	
	g.printGraph();
	g.dijkstra("1");


	return 0;
}






