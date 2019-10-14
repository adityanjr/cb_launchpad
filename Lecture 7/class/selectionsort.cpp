#include <bits/stdc++.h>
using namespace std;


void selectionSort(int* arr, int n){
	int minidx=0;
	for (int i = 0; i < n-1; ++i)
	{	minidx=i;
		for (int j = i; j<=n-1; j++)
		{
			if(arr[minidx]>arr[j]){
				minidx = j;
			}

		}

		int temp = arr[i];
		arr[i] = arr[minidx];
		arr[minidx] = temp;
		for (int i = 0; i < 6; ++i)
		{
			cout<<arr[i]<<", ";
		}
	cout<<"--------------------"<<endl;
	}

}

int main(int argc, char const *argv[])
{
	int arr[6] ={5,4,9,6,8,2};
	for (int i = 0; i < 6; ++i)
	{
		cout<<arr[i]<<", ";
	}
cout<<"--------------------"<<endl;
	selectionSort(arr,6);

	for (int i = 0; i < 6; ++i)
	{
		cout<<arr[i]<<", ";
	}
	cout<<"--------------------"<<endl;

	return 0;
}