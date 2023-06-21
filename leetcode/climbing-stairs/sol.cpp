#include <bits/stdc++.h>

using namespace std;

int climbStairs(int n) {
    unsigned long long a = 1, b = 0;
    for (int i = 1; i <= n; i++) {
        unsigned long long temp = a;
        a = a + b;
        b = temp;
    }
    return a;
}

int main() {
    cout << climbStairs(0) << endl;
    cout << climbStairs(1) << endl;
    cout << climbStairs(2) << endl;
    cout << climbStairs(3) << endl;
    cout << climbStairs(4) << endl;
    cout << climbStairs(5) << endl;
}
