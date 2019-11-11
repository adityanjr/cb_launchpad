#include <iostream>
#include <queue>
using namespace std;
void minsum(int arr[], int n){

	priority_queue<int, vector<int>, greater<int> > h;
	int i=0;
	while(i<n){
		h.push(arr[i]);
		i++;
	}
	int totalSum =0;
	int sum = h.top();
	h.pop();
	while(!h.empty()){
		sum+=h.top();
		h.pop();
		totalSum+=sum;
	}
	cout<<totalSum<<endl;

}

int main(int argc, char const *argv[])
{
	int arr[5] = {5, 2, 3, 6, 4};
	minsum(arr,5);
	
}