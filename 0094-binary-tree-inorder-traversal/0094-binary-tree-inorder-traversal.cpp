class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;

        while (current || !st.empty()) {
            while (current) { 
                st.push(current);
                current = current->left; // Move to the leftmost node
            }
            current = st.top();
            st.pop();
            result.push_back(current->val); // Visit the node
            current = current->right; // Move to the right subtree
        }

        return result;
    }
};
