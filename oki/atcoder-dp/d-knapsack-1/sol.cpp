#include <bits/stdc++.h>

#define br "\n"
#define int int64_t

using namespace std;

const int MAXN = 100 + 3;
const int MAXW = 1e5 + 3;

int w[MAXN];
int v[MAXN];
int dp[MAXN][MAXW];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, W;
    cin >> N >> W;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (j >= w[i])
                dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N][W] << br;
}
