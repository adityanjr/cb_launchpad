#include <iostream>
using namespace std;
int gcd(int a, int b){
	if(b==0){
		return a;
	}

	return gcd(b, a%b);
}


int lcm(int a, int b){
	// a*b = LCM(a,b) * GCD(a,b)
	int result = (a*b)/gcd(a,b);
	return result;
}

int main(int argc, char const *argv[])
{	

//	int result = gcd(10, 14);
	int result = gcd(14, 10);	
	cout<<result<<endl;
	int resultLCM = lcm(10, 14);

	return 0;
}