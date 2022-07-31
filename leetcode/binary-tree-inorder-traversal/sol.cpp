class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>();
        }
        vector<int> result;
        vector<int> left = inorderTraversal(root->left);
        for (int x : left) {
            result.push_back(x);
        }
        result.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        for (int x : right) {
            result.push_back(x);
        }
        return result;
    }
};
