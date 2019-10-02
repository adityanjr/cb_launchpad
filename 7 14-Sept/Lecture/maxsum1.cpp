#include <bits/stdc++.h>
using namespace std;

int maxsubarraysum(int* arr, int n){
	int maxsum=INT_MIN;
	for(int st = 0; st<n; st++){
		for(int ed=st; ed<n; ed++){
			int sum =0;
			for(int i = st; i<=ed; i++){
				sum+=arr[i];
				//cout<<arr[i]<<", ";
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



