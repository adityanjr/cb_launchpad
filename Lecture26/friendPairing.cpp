#include <bits/stdc++.h>
using namespace std;

int combinations(int num){
	if(num<=2){
		return num;
	}

	int result = combinations(num-1) + (num-1)*combinations(num-2);
	return result;


}
int arr[100];
int combinationsDP(int num){
	if(num==2){
		return num;
	}
	if(arr[num] != -1){
		return arr[num];
	}
	int result = combinationsDP(num-1) + (num-1)*combinationsDP(num-2);
	arr[num] = result;
	return result;
}


int main(int argc, char const *argv[])
{
	int num;
	cin>>num;
	int result = combinations(num);
	cout<<result<<endl;
	//fill(arr, arr+num, -1);
	for (int i = 0; i <= num; ++i)
	{
		arr[i] = -1;
	}
	arr[0] =0;
	arr[1] =1;
	int resultDP = combinationsDP(num);
	cout<<resultDP<<endl;
	

	return 0;
}