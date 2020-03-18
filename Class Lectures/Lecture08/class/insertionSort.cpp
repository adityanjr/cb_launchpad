#include <bits/stdc++.h>
using namespace std;


void insertionSort(int *arr,int n){
	for (int i = 1; i < n; ++i)
	{
		int j=i-1;
		while(j>=0 && arr[j]>arr[j+1]){
			swap(arr[j], arr[j+1]);
			j--;
		}
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
	insertionSort(arr,6);

	for (int i = 0; i < 6; ++i)
	{
		cout<<arr[i]<<", ";
	}
	cout<<"--------------------"<<endl;

	return 0;
}