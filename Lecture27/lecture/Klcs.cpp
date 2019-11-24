#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dp[100][100][100];

string st1 = "abcdgh";
string str2 = "bcdfi"
int len1 = str1.length();
int len2 = str2.length();
int klcs(int i, int j,int k){

	if(i == len1 || j==len2){
		return 0;
	}

	int res =0;
	if(dp[i][j][k] != -1){
		return dp[i][j][k];
	}

	if(str1[i] == str2[j]){
		res = 1+ klcs(i+1, j+1, k);
	}
	else{
		int q1=0,q2=0,q3 =0;
		if(k>0){
			q1 = 1 + klcs(i+1, j+1, k-1);
		}
		q2 = klcs(i, j+1, k);
		q3 = klcs(i+1, j, k);
		res = max(q1, max(q2,q3));
	}
	dp[i][j][k] = res;
	return dp[i][j][k];

}

int main(int argc, char const *argv[])
{
	string s1 = "acfgh";
	string s2 = "bcdegf";

	cout<<lcs(s1,s2)<<endl;
	return 0;
}