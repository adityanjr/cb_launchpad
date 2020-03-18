#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int> > pp;

vector<int> mergeKsorted(vector<vector<int> > v){

	int rows = v.size();
	vector<int> result;
	priority_queue<pp, vector<pp>, greater<pp> > h;
	int i=0;
	while(i<rows){
		pp ele = make_pair(v[i][0], make_pair(i,0));
		h.push(ele);
		i++;
	}

	while(!h.empty()){
		pp topEle = h.top();
		result.push_back(topEle.first);

		h.pop();

		int arrNo = topEle.second.first;
		int topEleIdx = topEle.second.second;
		if(topEleIdx + 1 < v[arrNo].size()){
			pp nextEle = make_pair(v[arrNo][topEleIdx+1], make_pair(arrNo,topEleIdx+1));
			h.push(nextEle);
		}
	}

	return result;
}

int main(int argc, char const *argv[])
{
	vector<vector<int> > v {{5,9,18,20,61},
							{6,11,22},
							{19,54,100,101},
							{1,3,10}};
	
	vector<int>result = mergeKsorted(v);
	for(auto i:result){
		cout<<i<<", ";
	}

	cout<<endl;
	return 0;
}