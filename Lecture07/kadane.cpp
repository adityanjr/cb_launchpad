#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, left=0, right=0;
	cin>>n;
	int arr[1000];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	int cs=0, ms=0, temp=0;   // Print subArray
	for(int i=0; i<n; i++){
		cs += arr[i];          //kadane
		if(cs>ms){
			ms=cs;
			right=i;
			left=temp;
		}
		if(cs<0){
			cs=0;
			temp=i+1;
		}
	}
	cout<<ms<<endl;
	for(int i=left; i<=right; i++){
		cout<<arr[i]<<", ";
	}
	return 0;
}
