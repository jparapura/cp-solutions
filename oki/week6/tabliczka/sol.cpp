#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

inline uint calc(uint a, uint b) {
    if (a % 2 == 0 || b % 2 == 0)
        return 0;
    return min(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    uint a, b;
    cin >> a >> b;
    cout << calc(a, b) << endl;
}
