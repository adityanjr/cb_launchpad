#include<iostream>
using namespace std;

//Recursive
int winesREC(int *arr,int start,int end,int year){

	//Base Case
	if(start > end){
		return 0;
	}

    //recursive call
    int inc_start = arr[start]*year + winesREC(arr, start+1, end, year+1);
    int inc_end = arr[end]*year + winesREC(arr, start, end-1, year+1);
    return max(inc_start, inc_end);
}

int dp[100][100] = {0};

//Top Down DP
int winesTD(int *arr,int start,int end,int year){

    //Base Case
	if(start > end){
		return 0;
	}
    if(dp[start][end] != 0) {
        return dp[start][end];
    }

    //recursive call
    int inc_start = arr[start]*year + winesTD(arr, start+1, end, year+1);
    int inc_end = arr[end]*year + winesTD(arr, start, end-1, year+1);

    return dp[start][end] = max(inc_start, inc_end);
}

//Bottom Up DP
int winesBUP(int *arr,int n) {

    int year = n;
    for (int i=0; i<n; i++) {
        dp[i][i] = year * arr[i];
    }
    year--;

    for (int i=n-1; i>=0; i--) {

        int tempYear = year;
        for (int j=i+1; j<n; j++) {

            int inc_i = arr[i] * tempYear;
            int inc_j = arr[j] * tempYear;
            int ans = max(dp[i+1][j] + inc_i, dp[i][j-1] + inc_j);
            dp[i][j] = ans;
            tempYear--;
        }
    }
    return dp[0][n-1];
}

int main(){

	int arr[] = {2,3,5,1,4};
    int n = 5;
    // cout << winesREC(arr, 0, n - 1, 1);

    // cout << winesTD(arr, 0, n - 1, 1)<<endl;
    // for(int i=0; i<n; i++){
	// 	for(int j=0; j<n; j++){
    //         cout << dp[i][j] << "  ";
    //     }
    //     cout << endl;
    // }

    cout << winesBUP(arr, n);

    return 0;
}