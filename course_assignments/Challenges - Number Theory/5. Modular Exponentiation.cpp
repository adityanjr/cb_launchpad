#include<iostream>
#define ll long long
using namespace std;
int power(ll x, ll y, ll p) {
    int res = 1;
	//Update x if it is more than or equal to p
    x = x % p; 
    while (y > 0) {
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
        // y must be even now 
        y = y>>1;  // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 
int main() {
   ll a, b, c;
   cin>>a>>b>>c;
   cout<<power(a,b,c); 
   return 0; 
} 