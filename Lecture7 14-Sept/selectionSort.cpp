#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[6]= {5,4,9,6,8,2};
	int ind_min=0;
	for (int i = 0; i < 5; i++)
	{
		ind_min=i;
		for (int j=i; j < 6; j++)
		{
			if (arr[ind_min]>arr[j]){
				ind_min = j;
			}
		}
		swap(arr[ind_min], arr[i]);

	}
	for(int k=0 ; k<6; k++){
		cout<<arr[k]<<", ";
	}
	return 0;
}
