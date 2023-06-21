#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long bigint;

const int N = 1000001;
const int MOD = 1000000007;
bigint cache[N][3];

bigint ile(int n, int s);

inline bigint calc(bigint result, int n, int s) {
    result += ile(n - 1, s) % MOD;
    result %= MOD;
    return result;
}

bigint ile(int n, int s) {
    if (n == 0 && s == 0)
        return 1;
    if (n <= 0) return 0;

    if (n < N && cache[n][s] != 0)
        return cache[n][s];

    bigint result = 0;
    switch (s) {
        case 0:
            result = calc(result, n, 0);
            result = calc(result, n, 1);
            result = calc(result, n, 2);
            break;
        case 1:
            result = calc(result, n, 0);
            result += (2 * ile(n - 2, 2)) % MOD;
            result %= MOD;
            break;
        case 2:
            result = calc(result, n, 0);
            result = calc(result, n, 1);
            break;
    }

    cache[n][s] = result;

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << ile(n, 0) << endl;
}
