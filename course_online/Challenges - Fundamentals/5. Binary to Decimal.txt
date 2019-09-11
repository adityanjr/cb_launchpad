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
    int num; 
    cin>>num;
    if( num>0 && num<=1000000000){
        cout<< binary(num) <<endl;
    }
}