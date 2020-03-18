#include <bits/stdc++.h>
using namespace std;

int dp[1050][1050];

int knapsackRec(int size[], int value[], int n, int s){

    if(s<=0 || n<0) return 0;
    if(dp[s][n] != -1) return dp[s][n];

    int ans = 0 ;

    ans = value[n-1] + knapsackRec(size,value,n-1,s-size[n-1]);
    ans = max (ans, knapsackRec(size,value,n-1,s));

    dp[s][n] = ans;
    return ans;
}

int knapsackDP(int size[], int value[], int n, int s){

    int dp2[1050][1050];

    for(int i=0; i<1050; i++){
        for(int j=0; j<1050; j++){
            dp2[i][j] = -1;
        }
    }

    for(int i=0; i<n; i++) dp2[0][i] = 0;
    for(int i=0; i<=s; i++) if(i>=size[0]) dp2[i][0] = value[0];

    for(int i=1; i<=s; i++){
        for(int j=1; j<n; j++){
            if (i>=size[j])
                dp2[i][j] = max (dp2[i][j-1], value[j] + dp2[i-size[j]][j]);
            else
                dp2[i][j] = dp2[i][j-1];
        }
    }
    return dp2[s][n-1];
}

int main(){
    int n,s;
    cin>>n>>s;
    int size[n];
    int value[n];
    for(int i=0; i<n; i++){
        cin>>size[i];
    }
    for(int i=0; i<n; i++){
        cin>>value[i];
    }

    for(int i=0; i<1050; i++){
        for(int j=0; j<1050; j++){
            dp[i][j] = -1;
        }
    }
    cout << knapsackDP(size,value,n,s) <<endl;
}