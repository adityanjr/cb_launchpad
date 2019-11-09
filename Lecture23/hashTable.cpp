#include <bits/stdc++.h>
using namespace std;

template<typename T>
class node
{
public:
	string key;
	T value;
	node<T>* next;
	node(string k, T val){
		key = k;
		value = val;
		next = NULL; 
	}
	~node(){
		if(next!=NULL){
			delete next;
		}
	}
	
};
template<typename T>
class hashTable
{	
	node<T>** arr;
	int currSize;
	int totalSize;

	int hashFunc(string k){
		int idx =0;
		int L = k.length();
		int mulFactor = 1;
		for (int i = 0; i < L; ++i)
		{	
			//mulFactor = pow(47,i);
			int result = ((k[L-i-1]%totalSize)*(mulFactor%totalSize))%totalSize;
			idx = ((idx%totalSize) + (result%totalSize))%totalSize;
			mulFactor = ((mulFactor%totalSize)*(47%totalSize))%totalSize;
		}
		return idx;
	}
	void rehash(){
		node<T>** oldArr = arr;
		int oldSize = totalSize;
		totalSize*=2;
		currSize =0;
		arr = new node<T>*[totalSize];
		for (int i = 0; i < totalSize; ++i)
		{
			arr[i] = NULL;
		}
		for (int i = 0; i < oldSize; ++i)
		{
			if(oldArr[i] != NULL){
				node<T>* temp = oldArr[i];
				while(temp!=NULL){
					insert(temp->key, temp->value);
					temp = temp->next;
				}

			}
		}

		for (int i = 0; i < oldSize; ++i)
		{
			delete oldArr[i];
		}
		delete[] oldArr;

	}

public:
	hashTable(int defaultSize = 5){
		totalSize = defaultSize;
		arr = new node<T>*[totalSize];
		for (int i = 0; i < totalSize; ++i)
		{
			arr[i] = NULL;
		}
		currSize =0;
	}
	
	void insert(string k, T val){
		int idx  = hashFunc(k);
		//cout<<idx<<endl;
		node<T>* newNode = new node<T>(k, val);
		newNode->next = arr[idx];
		arr[idx] = newNode;
		currSize++;

		float loadFactor = (float) currSize/(float)totalSize;
		//cout<<k<<endl;
		if(loadFactor > 0.5){
			cout<<"rehashing"<<endl;
			rehash();
		}
	}
	void print(){
		for (int i = 0; i < totalSize; ++i)
		{
			node<T>* temp = arr[i];
			//cout<<i<<endl;
			while(temp!=NULL){
				cout<<temp->key<<" "<<temp->value<<" --> ";
				temp=temp->next;
			}
			cout<<endl;
		}
	}
	T* search(string key){
		int idx =hashFunc(key);

			node<T>* temp = arr[idx];
			while(temp!=NULL){
				if (temp->key == key)
				{
					return &(temp->value);
				}
			}
		return NULL;
	}

	T& operator[](string key){
		T* valAdd = NULL;
		if(search(key) != NULL){
			valAdd = search(key);
		}else{
			T garbageVal;
			insert(key,garbageVal);
			valAdd = search(key);
		}
		return *valAdd;
	}
	
};


//void erase(){}
int main(int argc, char const *argv[])
{	
	hashTable<int> ht(5);
	ht.insert("mango", 100);
	ht.insert("banana", 200);
	ht.insert("apple", 300);
	ht.print();
	ht["mango"] = 500;
	ht["kiwi"] = 1000;
	ht.print();
	return 0;
}






