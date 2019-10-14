#include <bits/stdc++.h>
using namespace std;
	
int squareRoot(int num){
	int low =0, high = num;
	int root = 0;
	while(low<=high){
		int mid = low+ (high-low)/2;
		if(mid*mid == num){
			root = mid;
			return root;
		}
		else if(mid*mid > num){
			high = mid-1;
		}
		else{
			root = mid;
			low = mid+1;
		}
	}

	return root;
}
float squareRootwithPrecision(int num, int precision){
	int low =0, high = num;
	float root = 0;
	while(low<=high){
		int mid = low+ (high-low)/2;
		if(mid*mid == num){
			root = mid;
		}
		else if(mid*mid > num){
			high = mid-1;
		}
		else{
			root = mid;
			low = mid+1;
		}
	}

	float prec = 0.1;
	while(precision!=0){

		if(root*root == num){
			return root;
		}
		else if(root*root < num){
			root+=prec;
		}
		else{
			root-=prec;
			prec/=10;
			precision--;
		}

	}

	return root;

}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int root = squareRoot(n);
	cout<<root<<endl;
	float result = squareRootwithPrecision(15,4);
	cout<<result<<endl;
	return 0;
}








