#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;
int nums[MAXN];
int dp[MAXN];

typedef unsigned long long int bigint;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        bigint localMin = UINT64_MAX;
        for (int j = i - 1; i - j <= k && j >= 1; j--) {
            localMin = min(localMin, (bigint)dp[j] + (bigint)abs(nums[i] - nums[j]));
        }
        dp[i] = localMin;
    }

    cout << dp[n] << "\n";
    
}
