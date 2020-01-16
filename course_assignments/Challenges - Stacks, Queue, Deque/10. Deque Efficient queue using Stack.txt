#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        unsigned int size = q.size();
        this->q.push(x);
        while (size--){
            q.push(q.front());
            q.pop();
            }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
       return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }

    void printStack() {
        if (q.empty()) {
            cout << "stack is empty!";
            return;
        }
        queue<int> temp;
        temp = q;
        while (temp.size()) {
            cout << temp.front() << " ";
            temp.pop();
        }
    }
};

int main() {
    Stack pop_efficient;
    int n;
    cin>>n;
    
    for(int i=n-1; i>=0; i--){
        pop_efficient.push(i);
    }
    
    pop_efficient.printStack();

    return 0;
}