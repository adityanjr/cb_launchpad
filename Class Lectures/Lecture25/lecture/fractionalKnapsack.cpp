#include <iostream>
#include <vector>
using namespace std;

double fractinalKnapsack(int* wt,int* val,int totalWt, int num){
	vector<pair<double,int> > ratio;
	double result =0;
	for (int i = 0; i < num; ++i)
	{
		double r = (double)val[i]/wt[i];
		ratio.push_back(make_pair(r,i));
	}
	sort(ratio.begin(), ratio.end());
	for (int i = num-1; i >= 0; i--)
	{
		cout<<ratio[i].first<<endl;
	}
	for (int i = num-1; i >=0 && totalWt>0; i--)
	{
		if(wt[ratio[i].second] <= totalWt){
			totalWt-=wt[ratio[i].second];
			result+=val[ratio[i].second];
		}
		else{
			result+= totalWt*ratio[i].first;
			totalWt = 0;
		}
	}
	return result;
}
int main(int argc, char const *argv[])
{	int num=4;
	int wt[4] = {5,3,2,6};
	int val[4] = {10,19,12,20};
	int totalWt = 13; 
	cout<<fractinalKnapsack(wt,val,totalWt, num)<<endl;


	return 0;
}