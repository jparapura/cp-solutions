#include <bits/stdc++.h>

using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][1] = nums[0];
    dp[1][0] = nums[0];
    dp[1][1] = nums[1];
    for (int i = 2; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = nums[i] + max({dp[i - 1][0], dp[i - 2][1], dp[i - 2][0]});
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v1 = {1,2,3,1};
    cout << rob(v1) << endl;
    vector<int> v2 = {2,7,9,3,1};
    cout << rob(v2) << endl;
    vector<int> v3 = {2};
    cout << rob(v3) << endl;
    vector<int> v4 = {0};
    cout << rob(v4) << endl;
}
