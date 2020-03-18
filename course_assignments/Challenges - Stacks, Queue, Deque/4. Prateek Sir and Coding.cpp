
#include<stack> 
#include<iostream> 
#include<string>
using namespace std;
int main() {
    stack <int> S;
    int n;
    cin >> n;
    while (n) {
        int num;
        cin >> num;
        if (num == 1) {
            if (S.empty())
                cout << "No Code" << endl;
		    else {
                cout << S.top() << endl;
                S.pop();
            }
        }
        if (num == 2) {
            int num1;
            cin >> num1;
            S.push(num1);
        }
        n--;
    }
    return 0;
}