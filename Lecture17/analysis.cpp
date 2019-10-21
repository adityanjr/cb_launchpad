#include<iostream>
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
		// for (int i = 0; i < 6; ++i)
		// {
		// 	cout<<arr[i]<<", ";
		// }
		// cout<<"--------------------"<<endl;
	}
}

int main(int argc, char const *argv[])
{
	int arr[100000] = {0};
	int n = 100000;
	for (int i = 0; i < n; i++)
	{
		arr[i] = n-i;
	}

	clock_t startTime = clock();
	sort(arr, arr+n);
	clock_t endTime = clock();

	cout<<"time taken"<<endTime - startTime<<endl;
	for (int i = 0; i < n; i++)
		{
			arr[i] = n-i;
		}
	startTime = clock();
		bubbleSort(arr, n);
	endTime = clock();
	cout<<"time taken"<<endTime - startTime<<endl;
	return 0;
}