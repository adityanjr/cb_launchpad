#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[10] = {15, 9, 4, 16, 13, 7, 5, 3, 1, -2};
	int count=0;
	int max=0;
	for (int i = 9; i >= 0; i--)
	{
		if (arr[i]<arr[i-1]){
			count++;
			max = arr[i];
		}
	}
	cout<<count;
	
	return 0;
}
