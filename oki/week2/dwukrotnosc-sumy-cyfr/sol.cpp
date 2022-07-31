#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long bigint;

vector<bigint> cache;

inline bigint sumOfDigits(bigint n) {
    bigint result = 0;
    while (n != 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

inline int getIndex(bigint n) {
    auto it = find(cache.begin(), cache.end(), n);
    if (it != cache.end()) {
        int index = it - cache.begin();
        return index;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bigint N, X;
    cin >> N >> X;
    N--; // 0 indexing

    bigint a = X;
    cache.push_back(a);
    while (true) {
        a = 2 * sumOfDigits(a);
        if (getIndex(a) != -1)
            break;
        cache.push_back(a);
    }
    
    int offset = getIndex(a);
    int cycleLength = cache.size() - offset;

    int idx;
    if (N < cache.size())
        idx = N;
    else
        idx = ((N - offset) % cycleLength) + offset;
    cout << cache.at(idx) << endl;
}
