#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//static

	int arr1[5][4] = {
		{1,2,3,4},
		{11,12,13,14},
		{21,22,23,24},
		{31,32,33,34},
		{41,42,43,44}};
		
	// for (int i = 0; i < 5; ++i)
	// {
	// 	for (int j = 0; j < 4; ++j)
	// 	{
	// 		arr[i][j] = i*j;
	// 	}
	// }


	// for (int i = 0; i < 5; ++i)
	// {
	// 	for (int j = 0; j < 4; ++j)
	// 	{
	// 		cout<<arr[i][j]<<", ";
	// 	}
	// 	cout<<endl;
	// }


	//dynamic
	int row=5;
	int col =3;
	int** arr = new int*[row];

	for (int i = 0; i < row; ++i)
	{
		arr[i] = new int[col];
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			arr[i][j] = i*j;
		}
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout<<arr[i][j]<<", ";
		}
		cout<<endl;
	}



cout<<arr[3][2]<<endl;
cout<<*(arr[3]+2)<<endl;

	for (int i = 0; i < row; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;

cout<<arr[3][2]<<endl;

	return 0;
}