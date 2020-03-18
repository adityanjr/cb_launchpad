#include<iostream>
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
	}

}
int main(int argc, char const *argv[])
{
	int n =100;
	for (int i = 0; i < n; ++i)
	{
		cout<<i<<", ";
	}
	cout<<endl;
	for (int i = 0; i < n; i = i+2 )
	{
		cout<<i<<", ";
	}
	cout<<endl;

	for (int i = 0; i < n; i = i++ )
	{	
		for (int j = 0; j < n; j = j++ )
		{
			cout<<j<<", ";
		}
		cout<<endl;
	}
	cout<<endl;



	for (int i = 0; i < n; i = i++ )
	{	
		for (int j = i; j < n; j = j++ )
		{
			cout<<j<<", ";
		}
		cout<<endl;
	}
	cout<<endl;

	return 0;
}





