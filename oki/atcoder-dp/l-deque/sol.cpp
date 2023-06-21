#include <bits/stdc++.h>

#define br "\n"
#define int int64_t

using namespace std;

vector<int> a;
vector<vector<int>> dp;
vector<int> prefix;

int solve(int l, int r) {
    if (l == r) {
        dp[l][r] = a[l];
        return a[l];
    }

    if (dp[l][r] != -1)
        return dp[l][r];

    int pl = solve(l + 1, r);
    int pr = solve(l, r - 1);

    dp[l][r] = max(a[l] + (prefix[r] - prefix[l] - pl),
                   a[r] + (prefix[r - 1] - prefix[l - 1] - pr));
    return dp[l][r];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    a.assign(n + 2, 0);
    prefix.assign(n + 2, 0);
    dp.assign(n + 2, vector<int>(n + 2, -1));
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        if (i - 1 >= 0)
            prefix[i] = prefix[i - 1] + x;
    }

    cout << 2 * solve(1, n) - (prefix[n] - prefix[0]) << br;
}
