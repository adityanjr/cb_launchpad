#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int knapsack(int* wt,int* val,int num, int totalWt){
	if(num==0){
		return 0;
	}

	int inc = 0, exc =0;
	if((totalWt - wt[num-1])>=0){//include
		inc = val[num-1] + knapsack(wt, val, num-1, totalWt-wt[num-1]);
	}
	exc = knapsack(wt, val, num-1, totalWt);

	return max(inc,exc);
}

int knapsackBottomUp(int* wt,int* val,int num, int totalWt){

	int dp[num+1][totalWt+1];

	for (int i = 0; i <=num; ++i)
	{
		for (int j = 0; j <= totalWt; j++)
		{
			if(i==0 || j==0){
				dp[i][j] = 0;
			}
		}
	}

	for (int item = 1; item <= num; item++)
	{
		for (int w = 1; w <= totalWt; w++)
		{
			int inc =0, exc=0;

			//exclude
			exc = dp[item-1][w];

			//include
			if((w - wt[item-1]) >=0){
				inc = val[item-1] + dp[item-1][w - wt[item-1]];
			}

			dp[item][w] = max(inc, exc);
			
		}
	}


	for (int i = 0; i <=num; ++i)
	{
		for (int j = 0; j <= totalWt; j++)
		{
			
				cout<<dp[i][j]<<" ";
			
		}
		cout<<endl;
	}

	return dp[num][totalWt];

}



int main(int argc, char const *argv[])
{
	int wt[4] = {1,2,3,4};
	int val[4] = {60,80,150,165};
	int totalWt = 5;
	//cout<<knapsack(wt,val,4, totalWt)<<endl;
	cout<<knapsackBottomUp(wt, val, 4, totalWt)<<endl;

	return 0;
}