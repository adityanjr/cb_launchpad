#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	//priority_queue<int> h; //max heap
	priority_queue<int, vector<int>, greater<int> > h; //min heap
	h.push(10);
	h.push(5);
	h.push(11);
	h.push(2);
	h.push(4);
	h.push(19);
	h.push(22);
	h.push(1);
	cout<<h.top()<<endl;
	h.pop();
	cout<<h.top()<<endl;
	h.pop();
	cout<<h.top()<<endl;
	h.pop();
	cout<<h.top()<<endl;
	h.pop();
	cout<<h.top()<<endl;
	h.pop();
	cout<<h.top()<<endl;
	h.pop();
	cout<<h.top()<<endl;
	h.pop();
	cout<<h.top()<<endl;
	h.pop();
	cout<<h.top()<<endl;
	h.pop();
	return 0;
}