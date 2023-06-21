#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long bigint;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bigint A, B, C, D;
    cin >> A >> B >> C >> D;
    bigint product = C * D;
    for (bigint i = 1; i <= sqrt(C) * sqrt(D); i++) {
        if (product % i == 0) {
            bigint x = product / i;
            if (min(x, i) <= min(A, B) && max(x, i) <= max(A, B)) {
                cout << "TAK" << endl;
                return 0;
            }
        }
    }
    cout << "NIE" << endl;
}
