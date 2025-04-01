class Solution {
public:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;  // Both nodes are null
        if (!t1 || !t2) return false; // One of the nodes is null
        return (t1->val == t2->val)   // Values are equal
            && isMirror(t1->left, t2->right) // Left subtree of t1 with right subtree of t2
            && isMirror(t1->right, t2->left); // Right subtree of t1 with left subtree of t2
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root); // Check if the tree is its own mirror
    }
};
