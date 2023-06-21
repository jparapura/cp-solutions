#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long bigint;

vector<bigint> getDivisors(bigint n) {
    vector<bigint> res;
    stack<bigint> s;
    bool hasIntegerRoot = floor(sqrt(n)) == ceil(sqrt(n));
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            res.push_back(i);
            s.push(n / i);
        }
    }
    if (hasIntegerRoot) s.pop();
    while (s.empty() == false) {
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bigint A, B, C, D;
    cin >> A >> B >> C >> D;
    
    bigint product = C * D;
    // dzielików liczby n jest około cbrt(n)
    vector<bigint> divC = getDivisors(C);
    vector<bigint> divD = getDivisors(D);
    for (int i = 0; i < divC.size(); i++) {
        for (int j = 0; j < divD.size(); j++) {
            bigint x = divC[i] * divD[j];
            bigint y = product / x;
            if (min(x, y) <= min(A, B) && max(x, y) <= max(A, B)) {
                cout << "TAK" << endl;
                return 0;
            }
        }
    }
    cout << "NIE" << endl;
}
