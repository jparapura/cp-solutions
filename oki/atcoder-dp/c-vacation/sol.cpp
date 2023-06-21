#include <bits/stdc++.h>

#define br "\n"
#define int int64_t

using namespace std;

int dp[3];
int input[3];
int tmp[3];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // dp[i] - max szczęscie jeśli w aktualnym kroku wybiorę i-tą aktywność
    
    cin >> dp[0] >> dp[1] >> dp[2];

    for (int i = 0; i < n - 1; i++) {
        cin >> input[0] >> input[1] >> input[2];

        tmp[0] = input[0] + max(dp[1], dp[2]);
        tmp[1] = input[1] + max(dp[0], dp[2]);
        tmp[2] = input[2] + max(dp[1], dp[0]);

        dp[0] = tmp[0];
        dp[1] = tmp[1];
        dp[2] = tmp[2];
    }

    cout << max({dp[0], dp[1], dp[2]}) << br;
}
