#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
	node(int d){
		data =d;
		left = NULL;
		right = NULL;
	}
	
};

node* insertBST(node* root, int d){
	if(root == NULL){
		root = new node(d);
		return root;
	}
	if(d <= root->data){
		root->left = insertBST(root->left, d);
	}
	else{
		root->right = insertBST(root->right, d);
	}
	return root;
}

node* buildTree(){
	node* root = NULL;
	int d;
	cin>>d;
	while(d!=-1){
		root = insertBST(root, d);
		cin>>d;
	}
	return root;
}

bool search(node* root, int key){
	if(root == NULL){
		return false;
	}
	if(root->data == key){
		return true;
	}
	if(root->data > key){
		return search(root->left, key);
	}
	else{
		return search(root->right, key);
	}
}
bool isBST(node* root, int maxLeft, int minRight ){
	if(root == NULL){
		return true;
	}

	if(root-> data > maxLeft && root->data < minRight && 
		isBST(root->left, maxLeft, root->data) &&
		isBST(root->right, root->data, minRight)){
		return true;
	}
	return false;

}


class nodeAns{
public:
	int maxBSTsize;
	int leftmax;
	int rightmin;
	bool isBST;

	nodeAns(){
		isBST = true;
		maxBSTsize = 0;
		leftmax = INT_MIN;
		rightmin = INT_MAX;
	}
};


nodeAns largestBSTinBT(node* root){
	if(root==NULL){
		return nodeAns();
	}

	nodeAns leftSubTree= largestBSTinBT(root->left);
	nodeAns rightSubTree = largestBSTinBT(root->right);

	nodeAns ownAns;
	if(root-> data>= leftSubTree.leftmax && root->data< rightSubTree.rightmin
		&& leftSubTree.isBST && rightSubTree.isBST){
		ownAns.isBST = true;
		ownAns.leftmax = max(root->data, leftSubTree.leftmax);
		ownAns.rightmin = min(root->data, rightSubTree.rightmin);
		ownAns.maxBSTsize = leftSubTree.maxBSTsize + rightSubTree.maxBSTsize +1;
	}
	else{
		ownAns.isBST = false;
		ownAns.maxBSTsize = max(leftSubTree.maxBSTsize, rightSubTree.maxBSTsize);
	}
	return ownAns;

}

node* buildBinaryTree(){
	int d;
	cin>>d;
	if(d == -1){
		return NULL;
	}

	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();

	return root;
}

void inorderPrint(node* root){
	if(root == NULL){
		return;
	}
	inorderPrint(root->left);
	cout<<root->data<<" ";
	inorderPrint(root->right);
}

node* deleteBST(node* root, int key){
	if(root == NULL){
		return root;
	}
	else if(root->data > key){
		root->left = deleteBST(root->left, key);
		return root;
	}
	else if(root ->data < key){
		root->right = deleteBST(root->right, key);
		return root;
	}

	else if(root->data == key){
		//leaf node
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}
		//left child exist & no right child
		if(root->left != NULL && root->right == NULL){
			node* temp = root->left;
			delete root;
			return temp;
		}
		//right child exist & no left child
		if(root->left == NULL && root->right != NULL){
			node* temp = root->right;
			delete root;
			return temp;
		}
		//both child -> replace maxleft
		if(root->left != NULL && root->right != NULL){
			node* temp = root->left;
			while(temp->right!=NULL){
				temp = temp->right;
			}
			root->data = temp->data;
			root->left = deleteBST(root->left, root->data);
			return root;

		}
	}

	 return root;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    node* root = buildTree();
   // node* root = buildBinaryTree();
    inorderPrint(root);
    cout<<endl;
    // if(isBST(root, INT_MIN, INT_MAX)){
    // 	cout<<"BST"<<endl;
    // }
    // else{
    // 	cout<<"Not BST"<<endl;
    // }
    deleteBST(root, 15);
    inorderPrint(root);
    nodeAns ans = largestBSTinBT(root);
    cout<<ans.maxBSTsize<<endl;


    
    return 0;

}
//10 5 15 7 6 20 9 -1
//0 1 3 7 -1 -1 8 -1 -1 4 9 -1 -1 10 -1 -1 2 5 11 -1 -1 -1 6 -1 -1 
