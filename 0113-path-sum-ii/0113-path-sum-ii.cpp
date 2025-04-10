class Solution {
public:
    vector<vector<int>> result;

    void dfs(TreeNode* node, int targetSum, vector<int>& path, int currentSum) {
        if (!node) return;

        // Add current node value to path and update the sum
        path.push_back(node->val);
        currentSum += node->val;

        // Check if it's a leaf and the sum matches
        if (!node->left && !node->right && currentSum == targetSum) {
            result.push_back(path);  // Save a copy of the current path
        }

        // Recurse into left and right children
        dfs(node->left, targetSum, path, currentSum);
        dfs(node->right, targetSum, path, currentSum);

        // Backtrack - remove the current node value before returning
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path, 0);
        return result;
    }
};
