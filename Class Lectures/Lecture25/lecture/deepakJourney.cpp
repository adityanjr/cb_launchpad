#include <iostream>
#include <vector>
using namespace std;
int mincost(vector<int>cost,vector<int>petrol,int num){
	int minCost = cost[0];
	int totalcost =0;
	for (int i = 0; i < num; ++i)
	{
		minCost = min(minCost, cost[i]);
		totalcost += minCost* petrol[i];
	}
	return totalcost;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int num;
		cin>>num;
		vector<int> cost;
		vector<int> petrol;

		for (int i = 0; i < num; ++i)
		{	int c;	
			cin>>c;
			cost.push_back(c);
		}
		for (int i = 0; i < num; ++i)
		{	int c;	
			cin>>c;
			petrol.push_back(c);
		}

		cout<<mincost(cost,petrol, num)<<endl;
		
	}
	return 0;
}