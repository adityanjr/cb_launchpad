#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[5] = {5, 6, -7, 8, -9};
	int maxsum = INT_MIN;
	for (int i = 0; i < 5; i++) {
		for (int j = i; j < 5; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++) {
				sum += arr[k];
			}
			if (sum > maxsum) {
				maxsum = sum;
			}
		}
	}
	cout << maxsum;
	return 0;
}
