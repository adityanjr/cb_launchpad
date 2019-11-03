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

node* buildTree(){
	int d;
	cin>>d;
	if(d == -1){
		return NULL;
	}

	node* root = new node(d);
	root->leftChild = buildTree();
	root->rightChild = buildTree();

	return root;
}

void printTree(node* root){ //preorder
	if(root == NULL){
		return;
	}

	cout<<root->data<<" ";
	printTree(root->leftChild);
	printTree(root->rightChild);

}
void printInoderTree(node* root){ //Inorder
	if(root == NULL){
		return;
	}
	printInoderTree(root->leftChild);
	cout<<root->data<<" ";
	printInoderTree(root->rightChild);

}

void printPostTree(node* root){ //Postorder
	if(root == NULL){
		return;
	}
	printPostTree(root->leftChild);
	printPostTree(root->rightChild);
	cout<<root->data<<" ";

}


int height(node* root){ //O(n)
	if(root == NULL){
		return -1;
	}
	return	1 + max(height(root->leftChild), height(root->rightChild));
}
int countNodes(node* root){
	if(root == NULL){
		return 0;
	}
	return	1 + countNodes(root->leftChild) +  countNodes(root->rightChild);
}
int SumNodes(node* root){
	if(root == NULL){
		return 0;
	}
	return	root->data + SumNodes(root->leftChild) +  SumNodes(root->rightChild);
}

void printLevelK(node* root, int k){

	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	if(root->leftChild != NULL){
		printLevelK(root->leftChild, k-1);
	}
	if(root->rightChild != NULL){	
		printLevelK(root->rightChild, k-1);
	}
}

void printAllLevels(node* root){
	int levels = height(root);

	for (int i = 0; i <= levels; ++i)
	{
		printLevelK(root, i);
		cout<<endl;
	}
}

void levelOrder(node* root){
	queue<node*>q;
	q.push(root);
	q.push(NULL);
	while(q.size()>1){
		node* front = q.front();
		if(front == NULL){
			if(q.size()==1){
				return;
			}
			cout<<endl;
			q.push(NULL);
		}
		else{
			cout<<front->data<<" ";
			if(front->leftChild != NULL){
				q.push(front->leftChild);
			}
			if(front->rightChild != NULL){
				q.push(front->rightChild);
			}
		}
		q.pop();
	}
}


int diameter(node* root){ // O(N^2)
	if(root == NULL){
		return 0;
	}

	int heightDiameter = height(root->leftChild) + height(root->rightChild)+ 2;
	int leftDiameter = diameter(root->leftChild);
	int rightDiameter = diameter(root->rightChild);

	return max(heightDiameter, max(leftDiameter, rightDiameter));

}

int diameterOpt(node* root, int* h){
	int lh =-1, rh =-1;
	int leftDia = 0,rightDia = 0;
	if(root == NULL){
		*h = -1;
		return -1;
	}

	leftDia = diameterOpt(root->leftChild, &lh);
	rightDia = diameterOpt(root->rightChild, &rh);

	*h = max(lh,rh)+1;
	return max(leftDia, max(rightDia, lh+rh+2));
}


int main(int argc, char const *argv[])
{	
	node* root = buildTree();
	//printTree(root);
	cout<<endl;
	printInoderTree(root);
	cout<<endl;
	printPostTree(root);
	cout<<endl;
	printAllLevels(root);
	levelOrder(root);
	cout<<diameter(root)<<endl;
	
	int num = 5;
	cout<<diameterOpt(root, &num)<<endl;
	
	return 0;
}

//0 1 3 7 -1 -1 8 -1 -1 4 9 -1 -1 10 -1 -1 2 5 11 -1 -1 -1 6 -1 -1