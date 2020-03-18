#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n; 
	int d, result=0;
	cin>>n>>d;
	result = n>>d | n<<(sizeof(n)*8-d);
	cout<<result<<endl;
	return 0;
}