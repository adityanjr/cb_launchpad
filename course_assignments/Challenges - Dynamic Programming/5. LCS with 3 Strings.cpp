#include <iostream>
#include <cstring>

using namespace std;
#define ll long long

int dp[250][250][250];

int callLCS(string s1, string s2, string s3, int i, int j, int k){

    if(i==s1.length() || j == s2.length() || k == s3.length()) return 0;

    if(dp[i][j][k] != -1) return dp[i][j][k];

    int ans = 0;

    if((s1[i]==s2[j]) && (s2[j] == s3[k])) {
        ans  = 1 + callLCS(s1,s2,s3,i+1,j+1,k+1);

    } else {
        int one = callLCS(s1,s2,s3,i+1,j,k);
        int two = callLCS(s1,s2,s3,i,j+1,k);
        int three = callLCS(s1,s2,s3,i,j,k+1);
        ans  = max(three,max(one,two));
    }

    dp[i][j][k] = ans;
    return ans;
}

int main(){
    string s1,s2,s3;
    getline(cin,s1);
    getline(cin,s2);
    getline(cin,s3);

    for(int i=0; i<250; i++){
        for(int j=0; j<250; j++){
            for(int k=0; k<250; k++){
                dp[i][j][k] = -1 ;
            }
        }
    }
    cout << callLCS(s1,s2,s3,0,0,0);
}