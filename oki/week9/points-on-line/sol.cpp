#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int bigint;

// nie można zaalogować tablicy wielkości 1e9
const int MAXN = 1e5 + 7;
long long int nums[MAXN];

inline bigint combinations(bigint n) {
    return n * (n - 1) * (n - 2) / 6;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bigint n, d;
    cin >> n >> d;

    for (bigint i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }

    bigint l = 1;
    bigint r = 3;
    bigint localGroupsCnt = 0;
    bigint globalGroupsCnt = 0;
    while (r <= n) {
        if (abs(nums[r] - nums[l]) <= d) {
            localGroupsCnt = combinations(r - l + 1);
            r++;
        }
        else {
            //cout << "flush " << localGroupsCnt << l << " " << r << endl;
            globalGroupsCnt += localGroupsCnt;
            localGroupsCnt = 0;
            l++;
            if (r - l == 1)
                r++;
        }
    }

    globalGroupsCnt += localGroupsCnt;

    cout << globalGroupsCnt << endl;
}
