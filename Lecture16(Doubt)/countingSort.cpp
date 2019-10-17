#include <iostream>
using namespace std;
void countingSort(int* arr, int n){
	int maximum = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		maximum = max(maximum, arr[i]);
	}
	int* freqArr = new int[maximum+1]()c;
	//store the frequencies of all the numbers in frequency array
	for (int i = 0; i < n; ++i)
	{
		freqArr[arr[i]]++;
	}
	int j=0;
	// update the original array according to the frequencies
	for (int i = 0; i < maximum+1; ++i)
	{
		while(freqArr[i]>0){
			arr[j] = i;
			j++;
			freqArr[i]--;
		}
	}

}


int main(int argc, char const *argv[])
{
	int arr[12] = {5,9,2,4,3,1,2,9,8,7,15,10};
	int n=12;
	countingSort(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}