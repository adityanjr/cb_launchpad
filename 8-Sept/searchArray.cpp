#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, arr[5];
	for (int i = 0; i < 5; ++i)
	{
		cin>>n;
		arr[i]= {n};
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	int x,i ;
	cin>>x;
	for (i = 0; i < 5; ++i)
	{
		if (x==arr[i]) {
			cout<<"found at index "<<i<<endl;
			break;
		}
	}
	if(i==5) {
	 cout<<"not found";}
	return 0;
}