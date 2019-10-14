#include <bits/stdc++.h>
using namespace std;


void bubbleSort(int* arr, int n){

	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < n-1-i; j++)
		{
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] =arr[j+1];
				arr[j+1] = temp;

				//swap(&arr[j],&arr[j+1]);
			}
		}
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
	bubbleSort(arr,6);

	for (int i = 0; i < 6; ++i)
	{
		cout<<arr[i]<<", ";
	}
	cout<<"--------------------"<<endl;

	return 0;
}