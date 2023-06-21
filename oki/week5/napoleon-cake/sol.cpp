#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

const int MAXN = 2 * 100000 + 7;
uint nums[MAXN]; // mógłby być też zwykły int
int result[MAXN];

inline void testCase();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t-- > 0) {
        testCase();
    }
}

inline void testCase() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    uint acc = 0;
    for (int i = n - 1; i >= 0; i--) {
        acc = max(acc, nums[i]);
        result[i] = acc > 0 ? 1 : 0;
        if (acc != 0)
            acc--;
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}
