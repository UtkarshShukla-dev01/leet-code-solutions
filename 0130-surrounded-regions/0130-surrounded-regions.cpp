class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        // Lambda function to do DFS and mark connected 'O's from border as 'T'
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
            board[i][j] = 'T'; // Temporarily mark as safe
            dfs(i+1, j);
            dfs(i-1, j);
            dfs(i, j+1);
            dfs(i, j-1);
        };

        // Step 1: Mark all border-connected 'O's as safe
        for (int i = 0; i < m; ++i) {
            dfs(i, 0);          // Left border
            dfs(i, n - 1);      // Right border
        }
        for (int j = 0; j < n; ++j) {
            dfs(0, j);          // Top border
            dfs(m - 1, j);      // Bottom border
        }

        // Step 2: Flip all 'O' to 'X', and all 'T' back to 'O'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';     // Surrounded
                else if (board[i][j] == 'T') board[i][j] = 'O'; // Restore safe
            }
        }
    }
};
