#include <bits/stdc++.h>
using namespace std;
#define loop(x,n) for(int x=0; x<n; ++x);

class node{
public:
    node* left;
    node* right;
    vector<int> v;

    node(){
        left=NULL;
        right=NULL;
    }
};

bool valid(vector<int> v, int l, int r){
    for(int i=0; i<v.size(); i++){
        if(v[i]>=l && v[i]<= r) return true;
    }
    return false;
}


class Trie{
    node* root;
public:
    Trie(){
        root = new node();
    }

    void insert(int a, int index){
        node* curr = root;
        for(int i=31; i>=0; i--){
            bool b = a & (1<<i);
            if(b==1){
                if(!curr->right) curr->right = new node();
                curr = curr->right;
                curr->v.push_back(index);
            }
            else{
                if(!curr->left) curr->left = new node();
                curr = curr->left;
                curr->v.push_back(index);
            }
        }
    }

    int findMaxXorPair(int a, int l, int r){
        if(root==NULL) return 0;
        node* curr = root;
        int curr_xor = 0;

        for(int i=31; i>=0 && curr != NULL ; i--){
            bool b = a & (1<<i);
            if(b==1){
                if(!curr->left || !valid(curr->left->v,l,r)) {
                    curr = curr->right;
                    curr_xor += (1<<i);
                } 
                else {
                    curr = curr->left;
                }
            }
            else{
                if(!curr->right || !valid(curr->right->v,l,r)){
                    curr = curr->left;

                } 
                else{
                    curr = curr->right;
                    curr_xor += (1<<i);
                }
            }
        }
        return curr_xor;
    }
};

int main(){
    int n; cin>>n;
    Trie t;
    int index = 0;

    for(int i=0; i<n; i++){
        int q; cin>>q;

        if(q==0){
            int d; cin>>d;
            t.insert(d,index);
            index++;
        }
        else if(q==1){
            int l,r,x;
            cin>>l>>r>>x;
            cout<<t.findMaxXorPair(x,l-1,r-1)<<endl;
        }
    }
}