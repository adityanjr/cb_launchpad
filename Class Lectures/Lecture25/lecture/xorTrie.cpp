#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
};

class xorTrie
{	Node* root;
public:
	xorTrie() {
		root = new Node();
	}

	void insert(int n) {
		Node* curr = root;
		for (int i = 31; i >= 0; i--) {
			int curr_bit = (n >> i) & 1;
			if (curr_bit == 0) {
				if (curr->left == NULL) {
					curr->left = new Node();
				}
				curr = curr->left;
			} else {
				if (curr->right == NULL) {
					curr->right = new Node();
				}
				curr = curr->right;
			}
		}
		curr->val = n;
	}



	int query(int val, int n) {
		int max_xor = INT_MIN;
		Node* curr = root;
		int curr_xor = 0;
		for (int j = 31; j >= 0; j--) {
			int b = (val >> j) & 1;
			if (b == 0) {
				if (curr->right != NULL) {
					curr = curr->right;
				} else {
					curr = curr->left;
				}
			} else {
				if (curr->left != NULL) {
					curr = curr->left;
				} else {
					curr = curr->right;
				}
			}
		}
		return val ^ curr->val;
	}
};



int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int pre_xor = 0;
	int result = INT_MIN;
	xorTrie trie;
	for (int i = 0; i < n; i++) {
		pre_xor ^= arr[i];
		trie.insert(pre_xor);
		result = max(result, trie.query(pre_xor, n));
	}
	cout << result << endl;

	return 0;
}



