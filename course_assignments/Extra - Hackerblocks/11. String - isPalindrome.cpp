#include <iostream>
#include <cstring>
using namespace std;

string reverse(string s) {
    int len = s.size();
    for (int i=0; i<len/2; i++) {
        char ch = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = ch;
    } 
    return s;
}

bool isPalindrome(string s){
	if (s == reverse(s)) return true;
	else return false;
}

int main(){
	string x;
	cin>>x;
	cout<<boolalpha<<isPalindrome(x);
	return 0;
}