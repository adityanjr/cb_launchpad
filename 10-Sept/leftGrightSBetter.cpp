//Find and count all the elements before which all the elements are greater than it, and after which all are smaller
//better version
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{	//16 15 25 9 8 6 2 3
	int arr[100]={0};
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int count = 0;
	int leftSmaller[100]={0};
	
	leftSmaller[0] = INT_MAX;
	for (int i = 1; i < n; ++i)
	{	
		int minEle = min(arr[i-1], leftSmaller[i-1]);
		leftSmaller[i] = minEle;
		
	}
	//right array
	// int rightGreater[100] = {0};
	// rightGreater[n-1]=INT_MIN;
	// for (int i = n-2; i >=0 ; i--)
	// {
	// 	int maxEle = max(arr[i+1], rightGreater[i+1]);
	// 	rightGreater[i] = maxEle;
	// }

	//final loop
	// for (int i = 0; i < n; ++i)
	// {
	// 	int curr = arr[i];
	// 	if(leftSmaller[i]>curr && rightGreater[i]<curr){
	// 		count++;
	// 		cout<<curr<<", ";
	// 	}

	// }
	
// final loop without right array
	int rightMax = INT_MIN;
	for (int i = n-1; i >=0; i--)
	{
		int curr = arr[i];
		if(leftSmaller[i]>curr && rightMax<curr){
			count++;
			cout<<curr<<", ";
		}

		rightMax = max(rightMax, arr[i]);

	}

	cout<<"count: "<<count<<endl;




	return 0;


}





















