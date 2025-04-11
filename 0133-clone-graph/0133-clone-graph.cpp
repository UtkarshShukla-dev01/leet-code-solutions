class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // If the node was already cloned, return the clone
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Clone the node
        Node* clone = new Node(node->val);
        visited[node] = clone;

        // Clone all neighbors
        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};
