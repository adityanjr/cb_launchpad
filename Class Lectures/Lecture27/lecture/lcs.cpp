#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2){
	int dp[100][100];
	for (int i = 0; i <=s1.length(); ++i)
	{
		dp[0][i] = 0;
	}
	for (int i = 0; i <=s2.length(); ++i)
	{
		dp[i][0] = 0;
	}
	for(int i = 1; i <= s1.length(); i++){
		for (int j = 1; j <= s2.length(); j++)
		{
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[s1.length()][s2.length()];


}
int main(int argc, char const *argv[])
{
	string s1 = "acfgh";
	string s2 = "bcdegf";

	cout<<lcs(s1,s2)<<endl;
	return 0;
}