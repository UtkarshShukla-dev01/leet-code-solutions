/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root->left) return root;

        // Connect children of root
        root->left->next = root->right;

        // Connect across subtrees
        if (root->next) {
            root->right->next = root->next->left;
        }

        // Recur for left and right subtrees
        connect(root->left);
        connect(root->right);

        return root;
    }
};
