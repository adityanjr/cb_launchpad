#include <bits/stdc++.h>
using namespace std;

int lis(int* arr, int n){
	int dp[10];
	fill(dp, dp+n, 1);
	int LisLength = 1;
	for (int i = 1; i < n; ++i)
	{	int maxLength = 0;
		for (int j = 0; j < i; ++j)
		{
			if(arr[j] < arr[i]){
				maxLength = max(maxLength,dp[j]);
			}
		}
		dp[i] = maxLength+1;
		LisLength = max(LisLength, dp[i]);
	}
	return LisLength;
}

int lisOptimized(int*arr, int n){
	vector<int>v;
	v.push_back(arr[0]);
	int maxLength = 1;

	for (int i = 1; i < n; ++i)
	{
		int currEle = arr[i];
		auto start = v.begin();
		auto end = v.end();
		auto it = upper_bound(start, end, currEle);
		if(it == v.end()){
			v.push_back(currEle);
			maxLength++;
		}
		else{
			*it = currEle;
		}
	}
	return maxLength;

}


int main(int argc, char const *argv[])
{
	int arr[6] = {2,5,3,12,10,11};
	int n =6;
	//cout<<lis(arr,n)<<endl;
	cout<<lisOptimized(arr,n)<<endl;

	return 0;
}