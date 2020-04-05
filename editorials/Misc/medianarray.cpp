#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int k, l=0, r=A.size()-1, s=A.size()+B.size(), p, q, f=0, y, z;
    if(s%2==0)
        f=1;
    double ans;
    while(l<r){
        int mid=(l+r)/2;
        p=upper_bound(B.begin(),B.end(),A[mid])-B.begin();
        q=lower_bound(B.begin(),B.end(),A[mid+1])-B.begin();
        k=(q-p)/2;
        if(mid+k+1+p<s/2==s/2)
            break;
        else if(mid+k+1+p<s/2){
            l=mid;
            y=p;
            z=k;
            cout<<"yes";
        }
        else
            r=mid-1;
        f++;
        cout<<"mid:"<<f<<endl;
        cout<<"l:"<<l<<"r:"<<r<<endl;
        cout<<p<<"+"<<q<<"+";
    }
    cout<<y<<" "<<z<<endl;
    if(k==0){
        if(f){
            ans=(A[l]+A[l+1])/2;
            return ans;
        }
        return A[l];
    }
    if(f){
        ans=(max(A[l],B[p+k])+min(B[p+k+1],A[l+1])/2);
        return ans;
    }
    return B[p+k];
}

int main(){
    if(fopen("input.txt","r")){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    int m, n;
    cin>>m>>n;
    vector<int>v1(m);
    vector<int>v2(n);
    for (int i = 0; i < m; ++i)
    {
        cin>>v1[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin>>v2[i];
    }
    cout<<endl<<findMedianSortedArrays(v1,v2)<<endl;
    return 0;
}