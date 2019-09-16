#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int *a = new int;
	cout<<a<<endl;
	cout<<*a<<endl;
	int *b = new int(10);
	cout<<b<<endl;
	cout<<*b<<endl;
	int n;
	cin>>n;
	int *arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] =i*i;
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<", ";
		
	}
	delete a;
	delete[] arr;



	return 0;
}







