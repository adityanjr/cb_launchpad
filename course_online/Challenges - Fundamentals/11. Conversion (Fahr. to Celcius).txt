#Problem:
CONVERSION (FAHRENHEIT TO CELSIUS)
Take the following as input.

Minimum Fahrenheit value
Maximum Fahrenheit value
Step

Print as output the Celsius conversions. Use the formula C = (5/9)(F – 32) E.g. for an input of 0, 100 and 20 the output is
0 -17
20 -6
40 4
60 15
80 26
100 37

Input Format:
The first line of the input contains an integer denoting the Minimum Fahrenheit value. The second line of the input contains an integer denoting the Maximum Fahrenheit value. The third line of the input contains an integer denoting the Step.

Constraints:
0 < Min < 100 Min < Max < 500 0 < Step

Output Format
Print Fahrenheit and Celsius values separated by a tab. Each step should be printed in a new line.

Sample Input
0 
100 
20
Sample Output
0 -17 
20 -6 
40 4 
60 15 
80 26 
100 37
.........................................................

#include<iostream>
using namespace std;
int main() {
    int min_value, max_value, step;
    cin>>min_value>>max_value>>step;
    int i= min_value;
    while (i<=max_value){
        int C, x;
        x = i-32;
        C= (5*x)/9 ;
        cout<<i<<" "<<C<<endl;
        i= i+ step;
    }
	return 0;
}