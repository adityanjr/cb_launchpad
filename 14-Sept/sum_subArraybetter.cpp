#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[1000];
	int cumsum[1000] = {0};
	cin>>arr[0];
	cumsum[0] = arr[0];

	for(int i=1; i<n; i++){
		cin>>arr[i];
		cumsum[i] = cumsum[i-1] + arr[i];
	}

	int maxsum = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int sum = 0;
			sum = cumsum[j] - cumsum[i-1];
			if (sum > maxsum) {
				maxsum = sum;
			}
		}
	}	
	cout << maxsum;
	return 0;
}
