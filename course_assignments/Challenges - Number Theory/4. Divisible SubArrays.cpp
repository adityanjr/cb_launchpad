#include<iostream>
#include <cstring>
using namespace std;
#define ll long long
ll arr[1000005], prefixSum[1000005];
int main() {
    int t;
    cin>>t;
    while(t--){
        long int n;
        cin>>n;
        ll sum=0;
        memset(prefixSum, 0, sizeof(prefixSum));
        prefixSum[0]=1;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            sum +=arr[i];
            sum %=n;
            sum = (sum+n) % n;
            prefixSum[sum]++;
        }
        ll ans=0;
        for(int i=0; i<n; i++){
            ll num = prefixSum[i];
            ans += (num*(num-1))/2;
        }
        cout<<ans<<endl;
    }
	return 0;
}