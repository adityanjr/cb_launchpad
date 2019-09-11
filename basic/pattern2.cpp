#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int N;
	cout<<"enter a number"<<endl;
	cin>>N;
	for (int row = 1; row <=N; row++)
	{	
		for (int space = N-row; space >= 1; space--)
		{
			cout<<" ";
		}

		for (int col = 1; col<= row; col++)
		{
			cout<<"* ";
		}
		cout<<endl;
	}
	return 0;
}