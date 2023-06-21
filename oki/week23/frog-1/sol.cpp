#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;
int nums[MAXN];
int dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    dp[1] = 0;
    dp[2] = abs(nums[2] - nums[1]);

    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i - 1] + abs(nums[i] - nums[i - 1]), dp[i - 2] + abs(nums[i] - nums[i - 2]));
    }

    cout << dp[n] << "\n";
    
}
