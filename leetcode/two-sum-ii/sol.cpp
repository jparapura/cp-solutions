#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                vector<int> result = {l + 1, r + 1};
                return result;
            }
            if (sum > target)
                r--;
            else
                l++;
        }
        return { 0 };
    }
};

int main() {
    Solution s;
    vector<int> v1 = {2,7,11,15};
    vector<int> v2 = {2,3,4};

    vector<int> r1 = s.twoSum(v1, 9);
    cout << r1[0] << " " << r1[1] << endl;
    vector<int> r2 = s.twoSum(v2, 6);
    cout << r2[0] << " " << r2[1] << endl;
}
