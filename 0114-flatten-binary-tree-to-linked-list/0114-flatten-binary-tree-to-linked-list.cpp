class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        // Recursively flatten the left and right subtrees
        flatten(root->left);
        flatten(root->right);

        // Save references to left and right subtrees
        TreeNode* leftSubtree = root->left;
        TreeNode* rightSubtree = root->right;

        // Move the left subtree to the right
        root->left = nullptr;
        root->right = leftSubtree;

        // Traverse to the end of the new right subtree
        TreeNode* temp = root;
        while (temp->right) {
            temp = temp->right;
        }

        // Attach the original right subtree
        temp->right = rightSubtree;
    }
};
