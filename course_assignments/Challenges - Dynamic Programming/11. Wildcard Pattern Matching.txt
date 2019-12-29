#include<iostream>
#include <map>
using namespace std;
#define ll long long int

map<pair<ll,ll>,bool> dp;

bool doesPatMatches(string &str, string &pat, ll i,ll j){

    if(i==str.size() and j==pat.size()) return true;
    if(dp.find({i,j})!=dp.end()) return dp[{i,j}];

    if(i==str.size()){
        if(pat[j]!='*') return false;
        return dp[{i,j}] = doesPatMatches(str,pat,i,j+1);
    }

    if(j==pat.size()) return dp[{i,j}] = false;

    if(pat[j]=='*'){
        return dp[{i,j}] = doesPatMatches(str,pat,i,j+1) || doesPatMatches(str,pat,i+1,j);
    }

	else if(pat[j]=='?'){
        return dp[{i,j}]= doesPatMatches(str,pat,i+1,j+1);
    }

	else{
        return dp[{i,j}] = str[i]==pat[j] and doesPatMatches(str,pat,i+1,j+1);
    }
}

int main(){

    ll t=1;
    while(t--){
        dp.clear();
        string str,pat;
        cin>>str>>pat;
        cout<<doesPatMatches(str,pat,0,0)<<endl;    
    }
}