#include <bits/stdc++.h>
using namespace std;

void rotate(char* arr, int n){
	char ch = arr[n-1];
	for (int i = n-2; i >=0; i--)
	{	arr[i+1]=arr[i];
		
	}
	arr[0] =ch;
}

int main(int argc, char const *argv[])
{
	char arr[6];
	int k=2;
	cin>>arr;
	arr[5]='\0';

	cout<<arr<<endl;
	for (int i = 0; i < k; ++i)
	{
		rotate(arr,5);
	}

	cout<<arr<<endl;


	//better version
	int n=5;
	cin>>arr;
	char* tempArr = new char[k];
	for (int i = 0; i < k; ++i)
	{
		tempArr[i] = arr[n-k+i];
	}

	for (int i = n-1-k; i >=0; i--)
	{
		arr[i+k]=arr[i];
	}

	for (int i = 0; i < k; ++i)
	{
		arr[i] = tempArr[i];
	}

	cout<<arr<<endl;



	return 0;
}


