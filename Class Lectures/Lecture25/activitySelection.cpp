#include <iostream>
#include <vector>
using namespace std;
int maxTask(vector v, int n) {
    for (int i = 0; i < n; i++) {
        
    }
}
int main(int argc, char const *argv[]) {
    int res = 0;
    int t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int> > v;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            v.push_back(make_pair(x, y));
        }
        sort(v.begin(), v.end());
        cout << maxTask(v, n);
    }
}