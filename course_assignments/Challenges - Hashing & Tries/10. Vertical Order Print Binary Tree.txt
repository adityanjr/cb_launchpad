#include <bits/stdc++.h>
using namespace std;
#define loop(x,n) for(int x=0; x<n; ++x)

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

int height(node* root){
    if(root == NULL) return -1;
    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1,h2)+1;
}


node* buildTreeLevelWise(){
    int d; cin>>d;

	node*root = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){

		node*f = q.front();
		q.pop();
		int c1,c2;
		cin>>c1>>c2;

		if(c1!=-1){
			f->left = new node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new node(c2);
			q.push(f->right);
		}
	}
	return root;
}

void printLevelOrder(node* root){
    if(root == NULL) return;
    queue <node*> que;
    que.push(root);
    while(!que.empty()){
        cout << que.front()->data <<" ";
        if(que.front()->left != NULL) que.push(que.front()->left);
        if(que.front()->right != NULL) que.push(que.front()->right);
        que.pop();
    }
}

void vop(node* root, map<int, vector<int>> &m, int d=0){
    if(root==NULL) return;
    m[d].push_back(root->data);
    vop(root->left,m,d-1);
    vop(root->right,m,d+1);
}

void printVOP(map<int, vector<int>> m){
    for(auto it : m ){
        loop(j,it.second.size()) {
            cout<< it.second[j] << " ";
        }
        cout<<endl;
    }
}

int main(){
    int n; cin>>n;
    node* root = buildTreeLevelWise();
    map<int, vector<int>> m;
    vop(root,m);
    printVOP(m);
}