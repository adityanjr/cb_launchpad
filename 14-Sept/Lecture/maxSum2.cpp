#include <bits/stdc++.h>
using namespace std;

int maxsubarraysum(int* arr, int n){
	int maxsum=INT_MIN;

	int cumSum[5] = {0};
	cumSum[0] = arr[0];
	for (int i = 1; i < n; ++i)
	{
		 cumSum[i] = cumSum[i-1]+arr[i];
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout<<cumSum[i]<<", ";
	// }

	for(int st = 0; st<n; st++){
		int sum =0;
		for(int ed=st; ed<n; ed++){
			if(st==0){
				sum = cumSum[ed];
			}
			else{
				sum = cumSum[ed] - cumSum[st-1];
			}
			if(sum>maxsum){
				maxsum = sum;
			}
		}
	}
	return maxsum;
}

int main(int argc, char const *argv[])
{
	int arr[5] = {5,6,-7,8,-9};

	cout<<"max sum is: "<<maxsubarraysum(arr, 5)<<endl;

	return 0;
}



