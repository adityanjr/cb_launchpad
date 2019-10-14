#include <bits/stdc++.h>
using namespace std;

void addStar(string input, string output, int idx){
	if(idx==input.size()-1){
		output+=input[idx];
		cout<<output<<endl;
		return;
	}
	if(input[idx] =='x' && input[idx+1] == 'x'){
		output+="x*";
	}
	else{
		output+=input[idx];
	}

	addStar(input, output, idx+1);

}

int main(int argc, char const *argv[])
{
	string input = "axxbcdxxxxfgxh";
	cout<<input<<endl;
	addStar(input,"", 0);
	return 0;
}