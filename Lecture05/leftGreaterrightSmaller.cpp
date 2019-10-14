#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[8] = {16, 15, 25, 9, 8, 6, 2, 3}
	int count=0;

	for (int i = 0; i < 8; i++)
	{

		int current = arr[i];
		bool leftGreater = true;
		bool rightSmaller = true;

		for (int j = 0; j < i ; j++)
		{
			if( arr[j]<current){
				leftGreater = false;
				break;
			}
		}

		for (int k = i+1; i < 8; ++k)
			{
				if( arr[k]>current){
					rightSmaller = false;
					break;
				}
			}	
		if(leftGreater && rightSmaller){
			count++;
			cout<<current<<endl;
		}	
	}
	
	return 0;
}
