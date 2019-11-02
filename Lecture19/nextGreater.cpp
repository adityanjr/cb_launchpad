#include <iostream>
#include <stack>

using namespace std;
void nextGreater(int*arr, int n) {

	stack<int> st;
	st.push(arr[0]);
	for (int i = 1; i < n; ++i)
	{
		if (st.top() >= arr[i]) {
			st.push(arr[i]);
		}
		else if (st.top() < arr[i]) {
			while (st.empty() == false && st.top() < arr[i]) {
				cout << st.top() << " " << arr[i] << endl;
				st.pop();
			}
			st.push(arr[i]);
		}
	}
	while(!st.empty()){
		cout << st.top() << " " << -1 << endl;
		st.pop();
	}

}

int main(int argc, char const *argv[])
{
	int arr[7] = {12, 9, 8, 15, 6, 18, 7};
	nextGreater(arr, 7);

	return 0;
}