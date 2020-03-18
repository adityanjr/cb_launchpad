#include <bits/stdc++.h>
using namespace std;

int nthFib(int n){
	if(n==0 || n==1){
	//	cout<<"for "<<n<<"th term fib value is "<<n<<endl;
		return n;
	}
	int ans = nthFib(n-1) + nthFib(n-2);
	//cout<<"for "<<n<<"th term fib value is "<<ans<<endl;
	return ans;
}
int arr[100];
int nthFibTopDownDP(int n){
	if(n==0 || n==1){
	//	cout<<"for "<<n<<"th term fib value is "<<n<<endl;
		return n;
	}
	if(arr[n] != -1){
		return arr[n];
	}
	int ans = nthFibTopDownDP(n-1) + nthFibTopDownDP(n-2);
	arr[n] = ans;
	//cout<<"for "<<n<<"th term fib value is "<<ans<<endl;
	return arr[n];
}

int nthFibBottomUpDP(int n){
	arr[0] =0;
	arr[1] =1;

	for (int i = 2; i <= n; ++i)
	{
		arr[i] = arr[i-1]  + arr[i-2];
	}
	
	return arr[n];
}


int main(int argc, char const *argv[])
{
	/* code */
	int n = 45;
	
	//cout<<"recursive "<<nthFib(n)<<endl;
	for (int i = 0; i <= n; ++i)
	{
		arr[i] =-1;
	}
	arr[0]=0;
	arr[1]=1;
//	cout<<nthFibTopDownDP(n)<<endl;
	cout<<nthFibBottomUpDP(n)<<endl;

	return 0;
}




