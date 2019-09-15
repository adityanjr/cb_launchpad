#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[6]= {5,4,9,6,8,2};
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5-i; ++j)
		{
			if(arr[j]>arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
	for(int k=0 ; k<6; k++){
		cout<<arr[k]<<", ";
	}
	return 0;
}
