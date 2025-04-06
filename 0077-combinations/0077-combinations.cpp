class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;  // Final combinations
        vector<int> current;         // Current combination
        backtrack(1, n, k, current, result);
        return result;
    }

private:
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        // If the combination is of size k, add it to result
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Try each number from start to n
        for (int i = start; i <= n; ++i) {
            current.push_back(i);                      // Choose
            backtrack(i + 1, n, k, current, result);   // Explore
            current.pop_back();                        // Un-choose (backtrack)
        }
    }
};
