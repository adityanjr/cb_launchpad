#include <bits/stdc++.h>
using namespace std;
	
void printBinary(string output, int num){

	if(num==0){
		cout<<output<<endl;
		return;
	}

	int length = output.size();
	char lastDigit = output[length-1];

	if(lastDigit == '0'){
		printBinary(output+"0", num-1);
		printBinary(output+"1", num-1);
	}
	else{
		printBinary(output+"0", num-1);
	}


}


int main(int argc, char const *argv[])
{
	int num;
	cin>>num;

	printBinary("0",num-1);
	printBinary("1",num-1);
	return 0;
}








