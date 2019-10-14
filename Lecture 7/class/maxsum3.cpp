#include <bits/stdc++.h>
using namespace std;
int maxsubarraysum(int* arr, int n){
	int currentSum =0;
	int maxsum=0;
	int startidx=0,endidx=0,temp=0;
	for (int i = 0; i < n; ++i)
	{
		currentSum = currentSum+arr[i];
		if(currentSum>maxsum){
			maxsum = currentSum;
			endidx = i;
			startidx = temp;
		}

		if(currentSum < 0){
			currentSum = 0;
			 temp= i+1;
		}
	}
	for (int i = startidx; i <= endidx; ++i)
	{
		cout<<arr[i]<<", ";
	}
	return maxsum;

}
int main(int argc, char const *argv[])
{
	int arr[6] = {5,-6,7,8,-9,16};

	cout<<"max sum is: "<<maxsubarraysum(arr, 6)<<endl;

	return 0;
}
