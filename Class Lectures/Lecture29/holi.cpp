#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

template<typename T>
class Graph
{	list<pair<T,int> > *adjList;
public:
	int V;
	Graph(int v){
		V= v;
		adjList = new list<pair<T,int> >[V];
	}

	void addEdge(T u, T v, int weight, bool bidir = true ){
		adjList[u].push_back(make_pair(v,weight));

		if (bidir)
		{
			adjList[v].push_back(make_pair(u,weight));
		}
	}
	

	int dfsHelper(T src, int &ans,unordered_map<T, bool> &visited ){

		visited[src] = true;
		int x =0;
		int count = 1;
		for(auto neighbour: adjList[src]){
			T child = neighbour.first;
			int wt = neighbour.second;

			if(!visited[child]){
				x = dfsHelper(child, ans, visited);
				ans += 2 * wt * min(x, V-x); 
				count = 1+x;
			}
		}
		return count;
	}

	int dfs(){
		int ans =0;

		unordered_map<T, bool> visited;

		dfsHelper(0, ans, visited);
		return ans;

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
	int vertex;
	cin>>vertex;

	Graph<int> g(vertex);
	for (int i = 0; i < vertex; ++i)
	{
		int u, v, wt;
		cin>>u>>v>>wt;
		g.addEdge(u-1,v-1,wt);
	}

	cout<<g.dfs()<<endl;


	return 0;
}






