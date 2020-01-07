#include <iostream>
using namespace std;
int main() {
    int n,w;
    cin>>n>>w;
    int value[w+1];

    for(int i=1;i<=w;i++) cin>>value[i];

    int dp[w+1]; dp[0] = 0;

    for(int i=1; i<=w; i++) dp[i] = value[i];

    for(int j=2;j<=w;j++){
        for(int k=0;k<j;k++){
			if(value[j-k] == -1  || dp[k] == -1) continue;
			if(dp[j] == -1)
				dp[j] = dp[k] + value[j-k];
			else
				dp[j] = min(dp[j], dp[k] + value[j-k]);
        }
    }
    cout<<dp[w]<<endl;
}