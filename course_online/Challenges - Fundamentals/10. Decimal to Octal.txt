#include<iostream>
using namespace std;
int main() {
    long int n;
    cin>>n;
    int octalNum[100]; 
  
    // counter for octal number array 
    int i = 0; 
    while (n != 0) { 
  
        // storing remainder in octal array 
        octalNum[i] = n % 8; 
        n = n / 8; 
        i++; 
    } 
  
    // printing octal number array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        cout << octalNum[j];
	return 0;
}