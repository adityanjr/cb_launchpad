#include <iostream>
#include <cstring>
using namespace std;

int lcs(string str1, string str2) {

    int dp[100][100] = {0};
    int n = str1.length();  
    int m = str2.length();

    for (int i=0; i<=n; i++) {

        for (int j=0; j<=m; j++) {

        	if (i == 0 || j == 0) {
                dp[i][j] = 0;
        	}
            else if(str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

    return dp[n][m];
}

int main() {

    string str1 = "acfgh";
    string str2 = "bcdfgi";

    cout << lcs(str1, str2)<<endl;
	return 0;
}