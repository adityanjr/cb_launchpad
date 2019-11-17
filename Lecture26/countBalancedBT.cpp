#include <bits/stdc++.h>
using namespace std;

int count(int h){
	if(h == -1 || h==0){
		return 1;
	}

	int ans = 2*(count(h-1)*count(h-2))+(count(h-1)*count(h-1));
	return ans;
}
int dp[100];
int countTopDownDP(int h){
	if(h == -1 || h==0){
		return 1;
	}
	if(dp[h]!=-1){
		return dp[h];
	}
	int ansh1 = count(h-1);
	int ansh2 = count(h-2);
	int ans = 2*(ansh1*ansh2)+(ansh1*ansh1);
	dp[h] = ans;
	return ans;
}
int countBottomUpDP(int h){
	dp[0] =1;
	dp[1] = 3;
	for (int i = 2; i <= h; ++i)
	{
		dp[i] = 2*(dp[i-1]*dp[i-2])+(dp[i-1]*dp[i-1]);
	}

	return dp[h];
}



int main(int argc, char const *argv[])
{
	int countTrees = count(2);
	cout<<countTrees<<endl;
	for (int i = 0; i < 100; ++i)
	{
		dp[i]=-1;
	}
	cout<<countTopDownDP(2)<<endl;
	for (int i = 0; i < 100; ++i)
	{
		dp[i]=-1;
	}
	cout<<countBottomUpDP(3)<<endl;
	return 0;
}