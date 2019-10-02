#Problem:
INCREASING DECREASING SEQUENCE
Take the following as input.

A number (N)
Take N more numerical inputs
The N inputs for a sequence S = s1, s2, .., sN. Compute if it is possible to split sequence into two sequences -
s1 to si and si+1 to sN such that first sequence is strictly decreasing and second is strictly increasing. Print true/false as output.

Input Format:
Constraints:
0 < N < 1000 Each number in sequence S is > 0 and < 1000000000

Output Format
Sample Input
5 
1 
2 
3 
4 
5
Sample Output
true
................................................

#include<iostream>
using namespace std;
int main(){
    int n, i;
    cin>>n;
    long int *arr = new long int[n];
    for (int i = 0; i < n; ++i){
        cin>>arr[i];
    }

    for(i = 0; i < n-1; i++){
        if (arr[i] <= arr[i + 1]){ 
            break;
        }
    }
    for (i += 1; i<n-1; ++i){
        if(arr[i] >= arr[i + 1]){    
            cout<<"false";
            return 0;
        }
    }
    cout<<"true";
    return 0;
}
