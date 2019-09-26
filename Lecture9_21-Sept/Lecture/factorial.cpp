#include <bits/stdc++.h>
using namespace std;

int factorial (int n){
	//base case
	if(n==0){
		return 1;
	}

	int ans = n* factorial(n-1); // self work & recursive case
	return ans;

}



int main(int argc, char const *argv[])
{
	/* code */
	int n = 0;
	cout<< factorial(n)<<endl;
	return 0;
}