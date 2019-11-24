#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

template<typename T>
class Graph
{	unordered_map<T, list< pair<T, int> > > adjList;
	unordered_map<T, list<T> > parent;
	unordered_map<T, int > indegree;
public:
	Graph() {
	}

	void addEdge(T u, T v, int weight) {
		adjList[u].push_back(make_pair(v, weight));
		parent[v].push_back(u);
		indegree[v]++;

	}

	void topologicl() {
		queue<T> q;
		for (auto vertex : adjList)
		{	
			if (indegree[vertex.first] == 0) {
				q.push(vertex.first);
			}

		}
		while (!q.empty()) {
			T fr = q.front();
			q.pop();
			cout << fr << " --> ";
			for (auto neighbour : adjList[fr]) {
				indegree[neighbour.first]--;
				if (indegree[neighbour.first] == 0) {
					q.push(neighbour.first);
				}
			}
		}

	}



	void printGraph() {
		for (auto it : adjList)
		{
			T vertex = it.first;
			cout << vertex << "==";
			for (auto neighbour : it.second) {
				cout << neighbour.first << "-" << neighbour.second << " --> ";
			}
			cout << endl;
		}
	}

};

int main(int argc, char const *argv[])
{

	Graph<string> g;
	g.addEdge("Logic", "Prog", 5);
	g.addEdge("Syntax", "Prog", 10);
	g.addEdge("Prog", "ML", 10);
	g.addEdge("Prog", "Web Dev", 0);
	g.addEdge("ML", "Data sci", 16);
	g.addEdge("Data", "Data sci", 16);

	//g.printGraph();
	g.topologicl();


	return 0;
}






