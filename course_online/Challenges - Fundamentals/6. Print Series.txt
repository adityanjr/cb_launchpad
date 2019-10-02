#Problem:
PRINT SERIES
Take the following as input.

A number (N1)
A number (N2)
Write a function which prints first N1 terms of the series 3n + 2 which are not multiples of N2.

Input Format:
Constraints:
0 < N1 < 100 0 < N2 < 100

Output Format
Sample Input
10 
4
Sample Output
5 
11 
14 
17 
23 
26 
29 
35 
38 
41
...............................................

#include<iostream>
using namespace std;
int main() {
    int n1, n2, x;  
    cin>>n1>>n2;
    if (n1>0 && n1<100 && n2>0 && n2<100){
        for(int i=1; i<=n1; i++){
            x=(3*i)+2;
            if( x%n2 != 0){
                cout<<x<<endl;
            } 
            else n1++;
        }
    }
	return 0;
}