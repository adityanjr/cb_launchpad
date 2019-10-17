#include <iostream>
using namespace std;

bool compare(string str1, string str2){
	int length1 = str1.length();
	int length2 = str2.length();
	for (int i = 0; i < min(length1,length2); ++i)
	{
		if(str1[i] != str2[i]){
			return str1[i]<str2[i];
		}
	}

	return str1.length() > str2.length();
} 

int main(int argc, char const *argv[])
{
	int n =3;
	string arr[3] = {"bat", "apple", "batman"};
	sort(arr, arr+3, compare);
	for (int i = 0; i < 3; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}












