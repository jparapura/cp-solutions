#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int nums[MAXN];

void testCase();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> m;
    while (m-- > 0)
        testCase();
}

inline void testCase() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) { 
        cin >> nums[i];
    }

    int l = 1, r = n;
    if (nums[l] != nums[r]) {
        cout << r - l << endl;
        return;
    }
    while (l < r) {
        l++;
        if (nums[l - 1] != nums[l]) {
            cout << n - l << endl;
            return;
        }
        r--;
        if (nums[r + 1] != nums[r]) {
            cout << r - 1 << endl;
            return;
        }
    }

    cout << "BRAK" << endl;
}
