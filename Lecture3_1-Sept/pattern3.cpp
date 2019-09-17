#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int N;
	cin>>N;
	for (int row = 1; row <=N; row++)
	{
		for (int i = N-row; i >=1 ; i--)
		{
			cout<<" ";
		}
		for (int col = 1; col<= row; col++)
		{
			cout<<col;
		}
		for (int i = row-1; i >=1; i--)
		{
			cout<<i;
		}
		cout<<endl;
	}
	return 0;
}