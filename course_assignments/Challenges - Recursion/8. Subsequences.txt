#include<iostream>
using namespace std;

void subsequence(string str,int repo,string out[],int &outpos){
    if(str[repo]=='\0'){
        out[outpos]="";
        outpos++;
        return;
    }
    subsequence(str,repo+1,out,outpos);
    for(int i=0;i<outpos;i++){
        out[outpos+i]=out[i];
        out[i] = str[repo] + out[i];
    }
    outpos*=2;
}

int main(){
    string str;
    cin>>str;
    int count=0;
    int outpos=0;
    string out[1000];

    subsequence(str,0,out,outpos);
    for(int i=outpos-1;i>=0;i--){
        cout<<out[i]<<" ";
        count++;
    }
    cout<<count<<endl;
}