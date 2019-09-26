#include <bits/stdc++.h>
using namespace std;

int linearSearch(int* arr, int n, int key,int i){

	if(i==n){
		return -1;
	}


	if(arr[i] == key){
		return i;
	}
	return linearSearch(arr, n, key, i+1);

}


int main(int argc, char const *argv[])
{
	/* code */
	int n = 5;
	int arr[5] ={3, 5, 0, 9, 100};
	int key = 20;
	int idx = linearSearch(arr, n, key,0);
	cout<<idx<<endl;

	return 0;
}