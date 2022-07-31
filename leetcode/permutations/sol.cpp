class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty())
            return vector<vector<int>>();
        if (nums.size() == 1) {
            vector<vector<int>> res;
            res.push_back(nums);
            return res;
        }
        
        
        vector<vector<int>> global;
        for (int x : nums) {
            std::vector<int> subvector;
            std::copy_if(nums.begin(), nums.end(), std::back_inserter(subvector), [x](int i) {
                return i != x;
            });
            auto other = permute(subvector);
            for (vector<int> y : other) {
                vector<int> local;
                local.push_back(x);
                for (int n : y) {
                    local.push_back(n);
                }
                global.push_back(local);
            }
        }
        return global;
    }
};
