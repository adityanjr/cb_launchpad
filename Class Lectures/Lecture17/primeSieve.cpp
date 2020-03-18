#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int arr[100]={0};
	int n=100;

	// initially mark all numbers as Prime
	for (int i = 2; i < n; ++i)
	{
		arr[i] =1;
	}

	for (int i = 2; i < n ; ++i)
	{	
		if(arr[i] != 0){
			//mark all the multiples of that number as not prime
			for (int j = 2*i; j <n ; j+=i)
			{
				arr[j] =0;
			}
		}
	}
	//print primes
	for (int i = 0; i < n; ++i)
	{
		if(arr[i]){
			cout<<i<<" "<<endl;
		}
	}
	cout<<endl;

// // Optimization 1
// 	arr[2] =1;
// 	// initially mark all odd numbers as Prime
// 	for (int i = 3; i < n; ++i)
// 		{	if(arr[i]&1){
// 				arr[i] =1;
// 			}
// 		}
// 		//check multiples of odd numbers only
// 		for (int i = 3; i < n ; i+=2)
// 		{
// 			if(arr[i] != 0){
// 				// start from i*i as non prime numbers(multiples of i) smaller than i*i are already marked as non-prime by other smaller numbers
// 				for (int j = i*i; j < n ; j+=i)
// 				{
// 					arr[j] =0;
// 				}
// 			}
// 		}

// Optimization 2
	arr[2] =1;
	for (int i = 3; i < n; ++i)
		{	if(arr[i]&1){
				arr[i] =1;
			}
		}

		for (int i = 3; i*i <= n ; i+=2)
		{		// odd + odd =  even (as i and j are odd so, j=j+i will results j as an even value)
				// we have marked add even no. as non-prime already, so no need to traverse them again
				// therefore, we will take jumps of 2*i as j+=(2*i) will results j as an odd value
				for (int j = i*i; j < n ; j+=(2*i))
				{
					arr[j] =0;
				}
		}

	return 0;
}


