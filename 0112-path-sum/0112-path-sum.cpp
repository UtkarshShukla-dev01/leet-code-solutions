class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: if the tree is empty
        if (!root) return false;

        // If we reach a leaf node, check if the remaining sum equals the node's value
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        // Recursively check left and right subtrees with the reduced target sum
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};
