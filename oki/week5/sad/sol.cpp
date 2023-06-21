#include <bits/stdc++.h>

using namespace std;

typedef long long int bigint;

const int MAXN = 2 * 1000000 + 7;
int nums[MAXN];
bigint sums[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        sums[i] = nums[i] + sums[i - 1];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << sums[y] - sums[x - 1] << endl;
    }
}
