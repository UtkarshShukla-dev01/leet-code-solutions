#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (!node) return;

        path += to_string(node->val);

        if (!node->left && !node->right) { 
            result.push_back(path);
            return;
        }

        path += "->";

        dfs(node->left, path, result);
        dfs(node->right, path, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root) dfs(root, "", result);
        return result;
    }
};
