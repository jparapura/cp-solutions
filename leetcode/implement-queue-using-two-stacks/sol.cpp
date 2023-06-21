#include <bits/stdc++.h>

using namespace std;

class MyQueue {
public:
    stack<int> pushStack, peekStack;
    MyQueue() {
        
    }
    
    void push(int x) {
        while (peekStack.empty() == false) {
            pushStack.push(peekStack.top());
            peekStack.pop();
        }
        pushStack.push(x);
    }
    
    int pop() {
        int ans = peek();
        peekStack.pop();
        return ans;
    }
    
    int peek() {
        while (pushStack.empty() == false) {
            peekStack.push(pushStack.top());
            pushStack.pop();
        }

        return peekStack.top();
    }
    
    bool empty() {
        return pushStack.empty() && peekStack.empty();
    }
};


void printVector(vector<int>& a) {
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->peek();
    int param_3 = obj->pop();
    bool param_4 = obj->empty();
    cout << param_2 << param_3 << param_4;

}


