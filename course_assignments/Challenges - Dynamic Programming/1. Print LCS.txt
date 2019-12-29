#include <iostream>
#include <cstring>
using namespace std;
#define ll long long

string dp[1050][1050];

string printLCS(string s1, string s2, int i, int j){

    if(i==s1.length() || j == s2.length()) return "\0";
    //cout <<"1\n";

    if(dp[i][j] != "\0") return dp[i][j];

    string ans;

    if(s1[i]==s2[j]) {
        ans  = s1[i] + printLCS(s1,s2,i+1,j+1);

    } else {
        string one = printLCS(s1,s2,i,j+1);
        string two = printLCS(s1,s2,i+1,j);
        string three = printLCS(s1,s2,i+1,j+1);

        if(one.length() > two.length() ) ans = one;
        else ans = two;
        if(three.length() > ans.length()) ans = three;
    }
   // cout <<ans<<endl;
    dp[i][j] = ans;
    return ans;
}




int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);

    for(int i=0; i<1050; i++){
        for(int j=0; j<1050; j++){
            dp[i][j] = "\0";
        }
    }

    cout << printLCS(s1,s2,0,0);
}
