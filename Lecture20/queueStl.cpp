#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	queue<string> q;

	// q.push("abc");
	// q.push("fgh");
	// q.push("tyu");
	// cout<<q.front()<<endl;
	// q.pop();
	// cout<<q.front()<<endl;
	// q.pop();
	// cout<<q.front()<<endl;
	// q.pop();
	// cout<<q.front()<<endl;
	// q.pop();
	// cout<<q.front()<<endl;
	// q.pop();

	deque<int> dq;
	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);
	dq.push_front(4);
	dq.push_front(5);
	dq.push_front(6);
	for(auto it:dq){
		cout<<it<<endl;
	}



	return 0;
}





