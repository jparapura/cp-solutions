#include <bits/stdc++.h>

using namespace std;

int jump(vector<int>& nums) {
    vector<int> dp(nums.size(), INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j <= min((int)nums.size() - 1, i + nums[i]); j++) {
            dp[j] = min(dp[j], dp[i] + 1);
        }
    }
    return dp[nums.size() - 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v1 = {2,3,1,1,4};
    assert(jump(v1) == 2);
    vector<int> v2 = {2,3,0,1,4};
    assert(jump(v2) == 2);
    
}
