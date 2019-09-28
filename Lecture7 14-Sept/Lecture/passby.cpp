#include <bits/stdc++.h>
using namespace std;

//void sum(int num, int &totalsum){
void sum(int num, int *totalsum){	
	for (int i = 0; i <= num; ++i)
	{
		*totalsum+=i;
	}
	//return totalsum;
}

void squareArr(int arr1[10]){

	for (int i = 0; i < 10; ++i)
	{
		arr1[i] = arr1[i]*arr1[i];
	}

}

int main(int argc, char const *argv[])
{
	int n = 10;
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};

	//int result = sum(n);
	int result = 0;
//	sum(n,result);
	sum(n,&result);

//	cout<<result<<endl;
	squareArr(arr);
	for (int i = 0; i < 10; ++i)
	{
		cout<<arr[i]<<", ";
	}
	cout<<endl;

	return 0;
}







