#include <bits/stdc++.h>
using namespace std;

void printsubarrays(int* arr, int n){
	for(int st = 0; st<n; st++){
		for(int ed=st; ed<n; ed++){

			for(int i = st; i<=ed; i++){
				cout<<arr[i]<<", ";
			}
			cout<<endl;
		}

	}

}


int main(int argc, char const *argv[])
{
	int arr[5] = {1,2,3,4,5};

	printsubarrays(arr, 5);

	return 0;
}