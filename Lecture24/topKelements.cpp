#include <iostream>
#include <queue>
using namespace std;

void print(priority_queue<int, vector<int>, greater<int> > h){
	while(!h.empty()){
		cout<<h.top()<<", ";
		h.pop();
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	
	priority_queue<int, vector<int>, greater<int> > h; 
	int k;
	cin>>k;
	int num;
	cin>>num;
	int cs = 0;
	// while(scanf("%d",&num)!=EOF){
		
	// }
	while(num != -1000){
		if(num != -1){
			if(cs < k){
				h.push(num);
				cs++;
			}
			else if(h.top() < num){
				h.pop();
				h.push(num);
			}	
		}
		else{
			print(h);
		}
		cin>>num;
	}
	return 0;
}