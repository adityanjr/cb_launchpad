#include <iostream>
using namespace std;


class queue
{
	int rear;
	int front;
	int currSize;
	int totalSize;
	int* arr;
public:
	queue(int defaultSize = 5){
		 totalSize = defaultSize;
		 arr = new int[totalSize];
		 currSize =0;
		 front =0;
		 rear = totalSize-1;
	}
	bool isFull(){
		return currSize == totalSize;
	}
	bool isEmpty(){
		return currSize == 0;
	}

	void push(int data){
		if(isFull()){
			cout<<"queue is full"<<endl;
			return;
		}
		rear = (rear + 1) % totalSize;
		arr[rear] = data;
		currSize ++;
	}
	void pop(){
		if(isEmpty()){
			cout<<"queue is empty"<<endl;
			return;
		}
		front = (front + 1)% totalSize;
		currSize--;
	}
	int getFront(){
		if(isEmpty()){
			cout<<"queue is empty"<<endl;
			return -1;
		}
		return arr[front];
	}

	
	
};


int main(int argc, char const *argv[])
{	
	queue q(9);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	cout<<q.getFront()<<endl;
	q.pop();
	cout<<q.getFront()<<endl;
	q.pop();
	cout<<q.getFront()<<endl;
	q.pop();
	cout<<q.getFront()<<endl;
	q.pop();
	cout<<q.getFront()<<endl;
	q.pop();
	cout<<q.getFront()<<endl;
	q.pop();
	cout<<q.getFront()<<endl;

	
	return 0;
}



