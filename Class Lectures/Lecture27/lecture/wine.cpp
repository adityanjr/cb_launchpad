#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int calls;
int maxAmount(int* arr, int begin, int end, int year){
	calls++;
	if(begin > end){
		return 0;
	}

	int incStart = arr[begin]* year + maxAmount(arr, begin+1, end, year+1);
	int incEnd = arr[end] * year + maxAmount(arr, begin, end-1, year+1);
	int ans =  max(incStart, incEnd);

	return ans;
}
int dp[100][100];
int maxAmountTopDown(int* arr, int begin, int end, int year){
	calls++;
	if(begin > end){
		return 0;
	}
	if(dp[begin][end] != -1){
		return dp[begin][end];
	}

	int incStart = arr[begin]* year + maxAmountTopDown(arr, begin+1, end, year+1);
	int incEnd = arr[end] * year + maxAmountTopDown(arr, begin, end-1, year+1);
	int ans =  max(incStart, incEnd);
	dp[begin][end] = ans;
	return ans;
}

int maxAmountBottomUp(int* arr, int n){
	int year =n;
	for (int i = 0; i < n; ++i)
	{
		dp[i][i] = year * arr[i];
	}
	year--;
	for (int i = n-2; i >=0 ; i--)
	{	int tempYear = year;
		for (int j = i + 1; j < n; j++)
		{
			int inci = arr[i]*tempYear;
			int incj = arr[j]*tempYear;
			int ans = max(dp[i+1][j]+inci, dp[i][j-1]+incj);
			dp[i][j] =ans;
			tempYear--;
		}
	}

	return dp[0][n-1];


}


int main(int argc, char const *argv[])
{	
	int n=5;
//	int arr[5] = {2,3,5,1,4};
	int arr[5] = {2,5,3,8,1};
	for (int i = 0; i <=n; ++i)
	{
		for (int j = 0; j <=n; ++j)
		{
			dp[i][j]=-1;
		}
	}
	calls =0;
	cout<<maxAmount(arr,0, n-1, 1)<<endl;
	cout<<"recursive calls" <<calls<<endl;
	calls =0;
	cout<<maxAmountTopDown(arr,0, n-1, 1)<<endl;
	for (int i = 0; i <=n; ++i)
	{
		for (int j = 0; j <=n; ++j)
		{
			cout<<dp[i][j]<<", ";
		}
		cout<<endl;
	}
	cout<<"top-down calls" <<calls<<endl;
	for (int i = 0; i <=n; ++i)
	{
		for (int j = 0; j <=n; ++j)
		{
			dp[i][j]=-1;
		}
	}
	cout<<maxAmountBottomUp(arr, n);
	return 0;
}