#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int result = 0;
        int acc = 0;
        while (l < r) {
            acc = min(height[l], height[r]) * (r - l);
            result = max(result, acc);
            if (height[l] < height[r]) 
                l++;
            else
                r--;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> v1 = {1,8,6,2,5,4,8,3,7};
    vector<int> v2 = {1,1};

    cout << s.maxArea(v1) << endl;
    cout << s.maxArea(v2) << endl;
}
