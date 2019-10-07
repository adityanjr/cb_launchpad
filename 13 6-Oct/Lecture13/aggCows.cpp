#include <bits/stdc++.h>
using namespace std;


bool check(int* stalls, int N, int C, int minDiff){
	C--; // first cow is placed at stalls[0];
	int prevCow = 0;
	for (int i = 1; i < N ; ++i)
	{
		if((stalls[i] - stalls[prevCow]) >= minDiff ){
			C--;
			prevCow = i;
			if(C==0){
				return true;
			}
		}
	}
	return false;
}


int binarySearch(int* stalls, int N, int C){

	sort(stalls, stalls+N);
	int result = 0;
	int low =stalls[0], high = stalls[N-1];
	while(low <= high){
		int mid = low + (high-low)/2;
		bool isPossible = check(stalls, N, C, mid);
		if(isPossible){
			low = mid+1;
			result = mid;
		}
		else{
			high = mid-1;
		}
	}

	return result;
}


int main(int argc, char const *argv[])
{
	int stalls[5] = {1,2,8,4,9};
	int N = 5;
	int C =3;
	cout<<binarySearch(stalls, N, C)<<endl;
	return 0;
}





















