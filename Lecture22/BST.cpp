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
int insertBST(node* root, int d){
    if(root == NULL){ 
        root = new node(d);
        return root;
    }
    if(d <= root->data){
        root->leftChild = insertBST(root->leftChild, d);
    }
    else{
        root->rightChild = insertBST(root->rightChild, d);
    }
    return root;
}
node* buildTree(){
    node* root = NULL;
    int d;
    cin>>d;

    while(d !=-1){
        root = insertBST(root, d);
        cin>>d;
    }
}
void inOrder(node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->leftChild);
    cout<<root<<" ";
    inOrder(root->rightChild);
}
void leftBST(node* root){
    node* temp;
    while(temp->leftChild != NULL){
        temp = temp->leftChild;
    }
    if(temp <= root){
        return 1;
    }
}
void rightBST(node* root){
    node* temp;
    while(temp->rightChild != NULL){
        temp = temp->rightChild;
    }
    if(temp <= root){
        return 1;
    }
}
int main(){
    node* root = buildTree();
    inOrder(root);
    return 0;
}