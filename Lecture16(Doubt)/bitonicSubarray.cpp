//Find and count all the elements before which all the elements are greater than it, and after which all are smaller

#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[100]={12,4,78,90,45,23};
	int n = 6;
	//cin>>n;
	// for (int i = 0; i < n; ++i)
	// {
	// 	cin>>arr[i];
	// }
	int maxLength = 0;
	int incArr[100]={0};
	int decArr[100]={0};
	incArr[0]=1;
	decArr[n-1]=1;

	for (int i = 1; i < n; ++i)
	{	
		//inc array
		if(arr[i-1] < arr[i]){
			incArr[i] = incArr[i-1]+1;
		}
		else{
			incArr[i] = 1;
		}

		//dec array
		if(arr[n-i]<arr[n-i-1]){
			decArr[n-1-i] = decArr[n-i]+1;
		}
		else{
			decArr[n-1-i] = 1;
		}
	}
	
	int startidx =0, endidx =0; // to keep the track of first and last index
	//for maximum length
	for (int i = 0; i < n; ++i)
	{	
		int length = incArr[i] + decArr[i]-1;
		//maxLength = max(maxLength, length);

		if(maxLength<length){
			
			maxLength = length;
			startidx = i-incArr[i]+1;
			endidx = i+ decArr[i]-1;
		}
	}

	

	cout<<"mexlength : "<<maxLength<<endl;
	for (int i = startidx; i <= endidx; ++i)
	{
		cout<<arr[i]<<", ";
	}
cout<<endl;
	return 0;
}









