#include <bits/stdc++.h>
using namespace std;
void dnfSort(int* arr,int n){

	int high = n-1, low =0, mid =0;
	while(mid<=high){

		switch(arr[mid]){

			case 0: swap(arr[low],arr[mid]);
					low++;
					mid++;
					break;
			case 1: mid++;
					break;

			case 2: swap(arr[high],arr[mid]);
					high--;
					break;
		}

	}


}
int main(int argc, char const *argv[])
{
	int arr[7] ={2,1,0,1,2,0,1};
	for (int i = 0; i < 7; ++i)
	{
		cout<<arr[i]<<", ";
	}
cout<<"--------------------"<<endl;
	dnfSort(arr,7);

	for (int i = 0; i < 7; ++i)
	{
		cout<<arr[i]<<", ";
	}
	cout<<"--------------------"<<endl;

	return 0;
}