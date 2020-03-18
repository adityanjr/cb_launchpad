#include <iostream>
#include <vector>
using namespace std;
int maxTasks(int num,vector<pair<int, int> >vec){
	int tasks = 1;
	int lastActivityEndTime = vec[0].first;
	for (int i = 1; i < num; ++i)
	{
		if(vec[i].second >= lastActivityEndTime){
			lastActivityEndTime = vec[i].first;
			tasks++;
		}
	}
	return tasks;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int num;
		cin>>num;
		vector<pair<int, int> > vec;

		for (int i = 0; i < num; ++i)
		{
			int startTime, endtime;
			cin>>startTime>>endtime;
			vec.push_back(make_pair(endtime,startTime));
		}sort(vec.begin(), vec.end());
		cout<<maxTasks(num,vec)<<endl;
	}
	return 0;
}