#include <iostream>

using namespace std;

int main()
{
	int n;
	cout<<"Enter the value of (n) : ";	
	cin>>n;

	for (int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j>n-i)
			{
				cout<<j%10;
			}	
			else
				cout<<" ";
		}
		for(int j=1; j<i; j++)
		{
			cout<<n-j;
		}
		cout<<endl;
	}

	return 0;
}