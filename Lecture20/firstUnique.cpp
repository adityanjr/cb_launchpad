#include <bits/stdc++.h>
using namespace std;

char firstUnique(string str){
	queue<char> q;
	int freqArr[26] = {0};
	for (int i = 0; i < str.size(); ++i)
	{
		char curr = str[i];
		freqArr[curr-'a']++;

		if(freqArr[curr-'a'] >1 ){//repeated
			while(!q.empty() && freqArr[q.front()-'a']>1){
				q.pop();
			}

		}else{
			q.push(curr);
		}

	}
	return q.front();
}


int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	cout<<firstUnique(str)<<endl;
	return 0;
}