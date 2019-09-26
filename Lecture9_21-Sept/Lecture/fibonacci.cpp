#include <bits/stdc++.h>
using namespace std;

int nthFib(int n){
	if(n==0 || n==1){
		cout<<"for "<<n<<"th term fib value is "<<n<<endl;
		return n;
	}

	int ans = nthFib(n-1) + nthFib(n-2);

	cout<<"for "<<n<<"th term fib value is "<<ans<<endl;
	return ans;


}

int main(int argc, char const *argv[])
{
	/* code */
	int n = 4;
	
	nthFib(n);

	return 0;
}