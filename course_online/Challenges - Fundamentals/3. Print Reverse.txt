#include<iostream>
using namespace std;
int main() {
    long long int n;
    int rev=0;
    cin>>n;
    if (n>=0 && n<=1000000000){
      while (n>0){
        rev = rev*10 + n%10;
        n = n/10;
        }
    }
    cout << rev <<endl;
	return 0;
}