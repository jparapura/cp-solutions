#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int>& nums);

class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& numbers, int target, int startLeft) {
        int l = startLeft;
        int r = numbers.size() - 1;
        vector<vector<int>> result;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                vector<int> re = {-target, numbers[l], numbers[r]};
                result.push_back(re);
                r--;
                l = findNextIdx(numbers, l);
                if (l == -1)
                    break;
                continue;
            }
            if (sum > target)
                r--;
            else
                l++;
        }
        return result;
    }

    int findNextIdx(vector<int>& nums, int start) {
        for (int i = start + 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1])
                return i;
        }
        return -1;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            int next = findNextIdx(nums, i) - 1;
            vector<vector<int>> ts = twoSum(nums, -nums[i], i + 1);
            if (ts.size() == 0) {
                i = next != -2 ? next : i;
                continue;
            }
            for (auto& x : ts) {
                result.push_back(x);
            }
            if (next == -2)
                break;
            i = next;
        }
        return result;
    }
};

void printVector(vector<int>& nums) {
    for (int x : nums)
        cout << x << " ";
    cout << endl;
}

void print2dVector(vector<vector<int>>& v) {
    cout << "a" << endl;
    for (vector<int> x : v) 
        printVector(x);
    cout << endl;
}

int main() {
    Solution s;
    vector<int> v1 = {-1,0,1,2,-1,-4};
    vector<int> v2 = {0,1,1};
    vector<int> v3 = {0,0,0};
    vector<int> v4 = {-2,0,0,2,2};

    auto r1 = s.threeSum(v1);
    print2dVector(r1);
    auto r2 = s.threeSum(v2);
    print2dVector(r2);
    auto r3 = s.threeSum(v3);
    print2dVector(r3);
    auto r4 = s.threeSum(v4);
    print2dVector(r4);
}
