#include <bits/stdc++.h>

#define br "\n"
#define int int64_t

using namespace std;

const int MAXN = 1e5 + 3;

int heights[MAXN];
int dp[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cin >> heights[0];
    cin >> heights[1];
    dp[0] = 0;
    dp[1] = abs(heights[0] - heights[1]);
    for (int i = 2; i < n; i++) {
        cin >> heights[i];
        dp[i] = min(dp[i - 1] + abs(heights[i - 1] - heights[i]), dp[i - 2] + abs(heights[i - 2] - heights[i]));
    }

    cout << dp[n - 1] << br;
}
