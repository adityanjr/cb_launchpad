#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	char ch;
	cin >> ch;
	while (ch != '$') {
		cout << ch;
		cin.get(ch);
	}
	cout << endl;
	return 0;
}