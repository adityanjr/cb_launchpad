#include <iostream>
#include <vector>
using namespace std;

class heap
{	vector<int> pqueue;
	bool minHeap;
	bool compare(int a, int b){
		if(minHeap){
			return a > b;
		}
		return a < b;
	}
	void heapify(int i){
		int idx =i;
		int left_idx = idx*2;
		int right_idx = (idx*2)+1;
		int min_idx = idx;
		if(left_idx<pqueue.size()){
			if(compare(pqueue[idx],pqueue[left_idx])){
				min_idx = left_idx;
			}
		}
		if(right_idx<pqueue.size()){
			if(compare(pqueue[min_idx],pqueue[right_idx])){
				min_idx = right_idx;
			}
		}

		if(min_idx !=idx){
			swap(pqueue[min_idx], pqueue[idx]);
			heapify(min_idx);
		}
		return;
	}
public:
	heap(bool type = true){
		minHeap =type;
		pqueue.push_back(-1);
	}
	bool empty(){
		return pqueue.size()==1;
	}
	int top(){
		if(!empty()){
			return pqueue[1];
		}
		return -1;
	}
	void insert(int d){
		int idx = pqueue.size();
		pqueue.push_back(d);
		if(idx > 1){
			int parent_idx = idx/2;

			while(compare(pqueue[parent_idx],pqueue[idx]) && idx>1){
				swap(pqueue[parent_idx],  pqueue[idx]);
				idx = parent_idx;
				parent_idx = idx/2;
			} 
		}
	}
	void pop(){
		int idx_last = pqueue.size()-1;
		pqueue[1] = pqueue[idx_last];
		pqueue.pop_back();
		heapify(1);

	}
	
};

int main(int argc, char const *argv[])
{	
	heap h(false);

	h.insert(10);
	h.insert(5);
	h.insert(11);
	h.insert(2);
	h.insert(4);
	h.insert(19);
	h.insert(22);
	h.insert(1);
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

	int arr[10] = {10,5,11,2,4,19,22,1,51,0};
	for (int i = 0; i < 10 ; ++i)
	{	h.insert(arr[i]);
	}
	for (int i = 0; i < 10 ; ++i)
	{	arr[i] = h.top();
		h.pop();
	}
	for (int i = 0; i < 10 ; ++i)
	{	cout<<arr[i]<<",";
	}
	return 0;
}
