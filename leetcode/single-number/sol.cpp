#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int x : nums) {
        result ^= x;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << singleNumber(nums) << endl;
}
