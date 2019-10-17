#include <iostream>
using namespace std;

void merge(int* arr, int start, int mid, int end){

	int tempArr[end-start+1];
	int i=start, j = mid, k=0;

	while(i < mid && j <= end){
		if(arr[i]<=arr[j]){
			tempArr[k] = arr[i];
			k++;
			i++;
		}
		else{
			tempArr[k] = arr[j];
			k++;
			j++;
		}
	}
	while(i<mid){
		tempArr[k] = arr[i];
		k++;
		i++;
	}
	while(j<=end){
		tempArr[k] = arr[j];
		k++;
		j++;
	}
	j=0;
	for (i = start; i <= end; ++i){
		arr[i] = tempArr[j++];
	}
}

void mergeSort(int* arr, int start, int end){
	if(start>=end){
		return;
	}
	int mid = (start+end)/2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid+1, end);
	merge(arr, start, mid+1, end);
}


int main(){
    int n;
    cin>>n;
    int arr[n];
	for (int i = 0; i<n; ++i){
		cin>>arr[i];
	}
	mergeSort(arr, 0, n-1);
	for (int i = 0; i<n; ++i){
		cout<<arr[i]<<" ";
	}
	return 0;
}