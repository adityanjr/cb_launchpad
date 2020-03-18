#include <bits/stdc++.h>
using namespace std;

int* countSetBits(int n){
	int* arr = new int[n+1];

	arr[0] =0;
	arr[1] =1;
	for (int i = 2; i <= n; ++i)
	{
		if(i%2==0){
			arr[i] = arr[i/2];
		}
		else{
			arr[i] = 1+arr[i/2];
		}
	}
	return arr;
}

int main(int argc, char const *argv[])
{	int num=10;
	int* arr = countSetBits(num);

	for (int i = 0; i <= num; ++i)
	{
		cout<<arr[i]<<", ";
	}


	return 0;
}











