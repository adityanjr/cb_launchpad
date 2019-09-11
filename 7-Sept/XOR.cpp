#include <iostream>
using namespace std;

// unique number


int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int xor_result=0;
    while(n!=-1){
    	xor_result ^= n;
        cin>>n;
    }
    cout<<xor_result;
	return 0;
}