#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node* leftChild;
	node* rightChild;
	node(int d){
		data = d;
		leftChild = NULL;
		rightChild = NULL;
	}
};

node* insertBst(node* root, int d){

	if(root == NULL){
		root = new node(d);
		return root;
	}

	if(d <= root->data){
		root->leftChild = insertBst(root->leftChild, d);
	}
	else{
		root->rightChild = insertBst(root->rightChild, d);
	}
	return root;

}

node* buildTree(){

	node* root = NULL;
	int d;
	cin>>d;
	while(d != -1){
		root = insertBst(root, d);
		cin>>d;
	}
	return root;
}

bool search(node* root, int d){
	if(root == NULL){
		return false;
	}

	if(root->data == d){
		return true;
	}
	if(root->data < d){
		return search(root->rightChild, d);
	}
	else{
		return search(root->leftChild, d);
	}
}
void printInoderTree(node* root){ //Inorder
	if(root == NULL){
		return;
	}
	printInoderTree(root->leftChild);
	cout<<root->data<<" ";
	printInoderTree(root->rightChild);

}

node* deleteBST(node* root, int d){
	if(root == NULL){
		return root;
	}

	else if(root->data > d){
		root->leftChild = deleteBST(root->leftChild, d);
		return root;
	}
	else if(root-> data == d){
		//leaf node
		if(root->leftChild == NULL && root->rightChild == NULL){
			delete root;
			return NULL;
		}

		if(root->leftChild == NULL && root->rightChild != NULL){
			node* temp = root->rightChild;
			delete root;
			return temp;
		}
		if(root->leftChild != NULL && root->rightChild == NULL){
			node* temp = root->leftChild;
			delete root;
			return temp;
		}
		if(root->leftChild != NULL && root->rightChild != NULL){
			
			node* newNode = root->rightChild;
			while(newNode->leftChild != NULL){
				newNode = newNode->leftChild;
			}
			root->data = newNode->data;
			root->rightChild = deleteBST(root->rightChild, root->data);
			return root;
		}

	}
	else if(root->data < d){
		root->rightChild = deleteBST(root->rightChild, d);
		return root;
	}
	return root;

}

bool isBST(node* root, int leftmax, int rightmin){
	if(root == NULL){
		return true;
	}

	if(root->data < rightmin  && root->data >= leftmax &&
		isBST(root->leftChild,leftmax,root->data) && 
		isBST(root->rightChild,root->data,rightmin))
		{
			return true;
		}
		return false;
}
node* buildTreeBT(){
	int d;
	cin>>d;
	if(d == -1){
		return NULL;
	}

	node* root = new node(d);
	root->leftChild = buildTreeBT();
	root->rightChild = buildTreeBT();

	return root;
}

class nodeHelper
{
public:
	bool is_bst;
	int maxBSTsize;
	int leftmax;
	int rightmin;
	nodeHelper(){
		is_bst = true;
		maxBSTsize =0;
		leftmax = INT_MIN;
		rightmin = INT_MAX;
	}
};

nodeHelper greatestBSTinBT(node* root){


	if(root == NULL){
		return nodeHelper();
	}

	nodeHelper left = greatestBSTinBT(root->leftChild);
	nodeHelper right = greatestBSTinBT(root->rightChild);
	nodeHelper ans;
	if(root->data >= left.leftmax && root->data < right.rightmin && 
		left.is_bst && right.is_bst){
		ans.maxBSTsize = left.maxBSTsize + right.maxBSTsize + 1;
		ans.is_bst = true;
		ans.leftmax = max(left.leftmax, root->data);
		ans.rightmin = min(right.rightmin, root->data);
	}
	else{
		ans.is_bst = false;
		ans.maxBSTsize = max(left.maxBSTsize, right.maxBSTsize);

	}
	return ans;

}

int main(int argc, char const *argv[])
{
	//node* root = buildTreeBT();
	node* root = buildTree();
	//printInoderTree(root);
	// if(search(root, -3)){
	// 	cout<<"found"<<endl;
	// }else{
	// 	cout<<"not found"<<endl;
	// }
	// deleteBST(root, 2);
	// deleteBST(root, 100);
	//printInoderTree(root);
	// if(isBST(root, INT_MIN, INT_MAX)){
	// 	cout<<"bst"<<endl;
	// }else{
	// 	cout<<"not bst"<<endl;
	// }

	nodeHelper result = greatestBSTinBT(root);
	cout<<result.maxBSTsize<<endl;

	
}

//5 9 2 4 100 65 3 1 -1