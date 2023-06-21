#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long bigint;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bigint N;
    cin >> N;
    stack<bigint> s;
    bool hasIntegerRoot = floor(sqrt(N)) == ceil(sqrt(N));
    for (bigint i = 1; i <= sqrt(N); i++) {
        if (N % i == 0) {
            cout << i << endl;
            s.push(N / i);
        }
    }
    if (hasIntegerRoot) s.pop();
    while (s.empty() == false) {
        cout << s.top() << endl;
        s.pop();
    }
}
