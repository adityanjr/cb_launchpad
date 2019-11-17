#include <bits/stdc++.h>
using namespace std;

int minStepsRec(int n){
	if(n==1){
		return 0;
	}
	int stepsDiv3 =INT_MAX, stepsDiv2 = INT_MAX,stepsMinus1 = INT_MAX; 
	if(n%3 ==0){
		stepsDiv3 = 1 + minStepsRec(n/3);
	}
	if(n%2 == 0){
		stepsDiv2 = 1 + minStepsRec(n/2);
	}
	stepsMinus1 = 1+ minStepsRec(n-1);

	int ans = min(stepsMinus1, min(stepsDiv2, stepsDiv3));
	return ans;
}

int arr[100];
int minStepsTopDownDP(int n){
	if(n==1){
		return 0;
	}
	if(arr[n] != -1){
		return arr[n];
	}
	int stepsDiv3 =INT_MAX, stepsDiv2 = INT_MAX,stepsMinus1 = INT_MAX; 
	if(n%3 ==0){
		stepsDiv3 = 1 + minStepsTopDownDP(n/3);
	}
	if(n%2 == 0){
		stepsDiv2 = 1 + minStepsTopDownDP(n/2);
	}
	stepsMinus1 = 1+ minStepsTopDownDP(n-1);

	int ans = min(stepsMinus1, min(stepsDiv2, stepsDiv3));
	arr[n] = ans;
	return arr[n];
}
int minStepsBottomUpDP(int n){
	arr[1] =0, arr[2] = 1, arr[3] =1;

	for (int i = 4; i <= n ; ++i)
	{	
		int q1 = INT_MAX, q2 = INT_MAX, q3 = INT_MAX;
		if(i%3 == 0) q1 = arr[i/3];
		if(i%2 == 0) q2 = arr[i/2];
		q3 = arr[i-1];
		arr[i] = 1+min(q1, min(q2, q3));
	}
	
	arr[n] = ans;
	return arr[n];
}



int main(int argc, char const *argv[])
{
	int n =11;
	for (int i = 0; i <= n; ++i)
	{
		arr[i] = -1;
	}
	//cout<<minStepsRec(n)<<endl;
	cout<<minStepsTopDownDP(n)<<endl;
	return 0;
}









