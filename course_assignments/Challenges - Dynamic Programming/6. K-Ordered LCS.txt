#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dp[2050][2050][10];

int printLCS(int arr1[], int arr2[], int size1, int size2, int i, int j, int k){

    if(i==size1 || j == size2) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];

    int ans = 0;
    if(arr1[i]==arr2[j]) {
        ans  = 1 + printLCS(arr1,arr2,size1,size2,i+1,j+1,k);
    } 
	else {
        int one = printLCS(arr1,arr2,size1,size2,i+1,j,k);
        int two = printLCS(arr1,arr2,size1,size2,i,j+1,k);
        int three = printLCS(arr1,arr2,size1,size2,i+1,j+1,k);
        int four = 0;
        if(k>0) four = 1 + printLCS(arr1,arr2,size1,size2,i+1,j+1,k-1);

        ans  = max(four,max(three,max(one,two)));
    }

    dp[i][j][k] = ans ;
    return ans;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int arr1[n];
    int arr2[m];
    for(int j=0; j<n; j++){
        cin>>arr1[j];
    }
    for(int j=0; j<m; j++){
        cin>>arr2[j];
    }

    for(int i=0; i<2050; i++){
        for(int j=0; j<2050; j++){
            for(int k=0; k<10; k++){
                dp[i][j][k] = -1 ;
            }
        }
    }
    cout << printLCS(arr1,arr2,n,m,0,0,k);
}