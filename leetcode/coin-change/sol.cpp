#include<bits/stdc++.h>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        int m = INT_MAX;
        for (int x : coins) {
            if (i - x < 0)
                continue;
            if (dp[i - x] == -1)
                continue;
            m = min(m, 1 + dp[i - x]);
        }
        if (m == INT_MAX)
            dp[i] = -1;
        else
            dp[i] = m;
    }
    return dp[amount];
}

void p(vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> in1 = {1, 2, 5};
    cout << coinChange(in1, 11) << endl;
}
