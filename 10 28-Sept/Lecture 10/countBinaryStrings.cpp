#include <bits/stdc++.h>
using namespace std;
	
int countBinary(string output, int num){

	if(num==0){
		cout<<output<<endl;
		return 1;
	}

	int length = output.size();
	char lastDigit = output[length-1];
	int count = 0;
	if(lastDigit == '0'){

		count += countBinary(output+"0", num-1) + countBinary(output+"1", num-1);
		 
	}
	else{
		count += countBinary(output+"0", num-1);
	}

	return count;
}


int main(int argc, char const *argv[])
{
	int num;
	cin>>num;
	int result =0;
	result += countBinary("0",num-1);
	result += countBinary("1",num-1);
	cout<<result<<endl;
	return 0;
}








