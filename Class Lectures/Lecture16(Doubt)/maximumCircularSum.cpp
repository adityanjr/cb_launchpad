#include<bits/stdc++.h>
using namespace std;

//to find maximum subarray sum -> Kadane's also
int kadane(int a[], int n)
{
	int max_so_far = 0, max_ending_here = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		max_ending_here = max_ending_here + a[i];
		if (max_ending_here < 0)
			max_ending_here = 0;
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;
	}
	return max_so_far;
}


int maxCircularSum(int a[], int n)
{
// Case 1: find maximum sum using standard kadane's algo
int maxSum1 = kadane(a, n);

// Case 2: find the maximum sum that includes corner elements
int total_Sum = 0, i;
for (i=0; i<n; i++)
{
		total_Sum += a[i];     // totalArraySum
		a[i] = -a[i];       // change the sign of all the elements
}

// max sum with corner elements will be: totalArraySum - (-max subarray sum of inverted array)
total_Sum = total_Sum + kadane(a, n);

//resultant max sum = maximum of two sums
return (total_Sum > maxSum1)? total_Sum: maxSum1;
}


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
       int n;
       cin>>n;
       int a[n];
       for(int j=0;j<n;j++)
       {
       	cin>>a[j];
       }
        cout<< maxCircularSum(a, n) <<endl;
	}
	return 0;
}
