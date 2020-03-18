#include <bits/stdc++.h>
using namespace std;


int partition(int* arr, int low, int high){
	int pivot = arr[high];
	int idx = low, i = low;
	while(i<high){
		if(arr[i]<pivot){
			swap(arr[i], arr[idx]);
			idx++;
		}
		i++;
	}
	swap(arr[idx], arr[high]);
	return idx;
}

void quicksort(int* arr, int low, int high){
	if(low > high){
		return;
	}
	int pidx = partition(arr, low, high);
	quicksort(arr, low, pidx-1); // FOR LEFT ARRAY
	quicksort(arr, pidx+1, high);// FOR RIGHT ARRAY
}
int main(int argc, char const *argv[])
{
	int arr[] = {9, 6, 3, 4, 15, 5};
	for (int i = 0; i < 6; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	quicksort(arr, 0, 5);
	for (int i = 0; i < 6; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}










