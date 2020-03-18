#Problem:
VON NEUMAN LOVES BINARY
Given a binary number ,help Von Neuman to find out its decimal representation. For eg 000111 in binary is 7 in decimal.

Input Format:
The first line contains N , the number of binary numbers. Next N lines contain N integers each representing binary represenation of number.

Constraints:
N<=1000 Digits in binary representation is <=16.

Output Format
N lines,each containing a decimal equivalent of the binary number.

Sample Input
4
101
1111
00110
111111
Sample Output
5
15
6
63
..............................................

#include<iostream>
using namespace std;

int binary(int n) {
    int num = n; 
    int dec_value = 0; 
    int base = 1;  
    int temp = num; 
    while (temp>0) { 
        int last_digit = temp % 10; 
        temp = temp / 10; 
        dec_value += last_digit * base; 
        base = base * 2; 
    }    
	return dec_value;
}

int main() {
    int N, num; 
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>num;
        cout<< binary(num) <<endl;
    }
}