#include <bits/stdc++.h>
using namespace std;

bool check(int* boards, int B, int P, int minLen){
	int sum=0;
	P--;
	for(int i=0;i<B;i++){
		if(boards[i] > minLen){
			return false;
		}
		

		if((sum+boards[i]) > minLen){
			P--;
			if(P<0){
				return false;
			}
			sum=0;
		}
		sum+=boards[i];

	}
	return true;
}

int minTime(int* boards, int B, int P){

	int min = INT_MAX;
	int total =0;

	for (int i = 0; i < B; ++i)
	{
		if(min>boards[i]){
			min=boards[i];
		}
		total+=boards[i];
	}


	int low = min, high= total, result =0;

	while(low<=high){
		int mid = low+(high-low)/2;
		bool isPossible = check(boards, B, P, mid);
		if(isPossible){
			high = mid-1;
			result = mid;
		}
		else{
			low = mid+1;
		}

	}
	return result;
}


int main(int argc, char const *argv[])
{	
	int painters =2 , time = 10;
	int boards[] = {1,3,2,4};

	int minimumTime = minTime(boards, 4, painters)*time;
	cout<<minimumTime<<endl;


	return 0;
}







