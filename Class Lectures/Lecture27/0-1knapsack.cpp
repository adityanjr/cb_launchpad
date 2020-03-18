#include <iostream>
using namespace std;

//Recursive
int knapsackREC(int* wt, int* val, int num, int totalwt) {

    //base case -> when no items left
    if(num==0) {
        return 0;
    }

    int inc = 0, exc = 0;

    //recursive call
    if(totalwt - wt[num-1] >= 0) {
        inc = val[num - 1] + knapsackREC(wt, val, num - 1, totalwt - wt[num - 1]);
    }
    exc = knapsackREC(wt, val, num - 1, totalwt);

    return max(inc, exc);
}

//Bottoms Up
int knapsackBUP(int* wt, int* val, int num, int totalwt) {

    int dp[num+1][totalwt+1];

    for (int i = 0; i<=num; i++) {

        for (int j = 0; j<=totalwt; j++) {

            //fill 0, with 0 items and 0 wt
            if(i==0 || j==0) {
                dp[i][j] = 0;
            }
        }
    }
    for (int item = 1; item<=num; item++) {

        for (int w = 0; w<=totalwt; w++) {

            int inc = 0, exc = 0;
            
            //excluding
            exc = dp[item - 1][w];

            //including
            if(w-wt[item-1] >= 0) {
                inc = val[item - 1] + dp[item - 1][w - wt[item-1]];
            }

            //update with max of including vs excluding
            dp[item][w] = max(inc, exc);
        }
    }
    //for printing table also
    for (int i = 0; i<=num; i++) {

        for (int j = 0; j<=totalwt; j++) {

            cout<<dp[i][j]<<"  ";
        }
        cout << endl;
    }

    return dp[num][totalwt];
}

int main() {

    int wt[4] = {1, 2, 3, 4};
    int val[4] = {60, 80, 150, 165};
    int totalwt = 5;

    // cout << knapsackREC(wt, val, 4, totalwt);
    cout << knapsackBUP(wt, val, 4, totalwt);
}