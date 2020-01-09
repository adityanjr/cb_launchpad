#include<iostream>
#include<list>
#include<map>
using namespace std;

void intersectionLL(list <int> LL1, list <int> LL2){
   map<int, int> m;// value->count
    map<int, int> res;// value->count
    for(auto x:LL1){
        m[x]++;
    }
    for(auto x:LL2){
        if(m[x]){ // if count>0 
            res[x]++;
            m[x]--;
        }
    }
    // print
    int s=res.size();
    for(auto x:res){
        for(int i=0; i<x.second; i++){
            cout<<x.first;
            if(s > 1)
                cout<<", ";
        }
        s--;
    }
}

int main(){
    list <int> l1, l2; 
    int n,c;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>c;
        l1.push_back(c);
    }
    for(int i=0; i<n; i++){
        cin>>c;
        l2.push_back(c);
    }
    cout<<"[";
    intersectionLL(l1, l2);
    cout<<"]\n";

    return 0;
}
/*
O(n) time using hashing.
    -> put all in hash table.
    -> search each element in map if exists then it is intersection.
    -> put all keys in map of both lists only unique keys will be stored i.e union.

*/