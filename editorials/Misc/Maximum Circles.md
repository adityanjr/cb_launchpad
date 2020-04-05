## Problem Name : Maximum Circles

### Topic : Greedy

#### Difficulty : Medium

### EXPLANATION

This is simple activity selection problem. Consider, for each circle, its beginning at $$c-r$$ and ending at $$c+r$$. Now greedily select activities by sorting them according to their ending.

#### Time Complexity : O($$NlogN$$).

```c++
#include<iostream>
#include<algorithm>
using namespace std;

struct act{
    int beg; int end;
};

bool comp(act a,act b){
    if(a.end==b.end) return a.beg<b.beg;
    return a.end<b.end;
}

int main() {
    int n;
    cin>>n;
    act arr[n];
    int c;int r;
    for(int i=0;i<n;++i){
        cin>>c;
        cin>>r;
        arr[i].beg=c-r;
        arr[i].end=c+r;
    }
    sort(arr,arr+n,comp);
    int curr=arr[0].end;
    int done=1;
    for(int i=1;i<n;++i){
        if(arr[i].beg>=curr){
            done++;
            curr=arr[i].end;
        }
    }
    cout<<n-done<<endl;
	return 0;
}
```