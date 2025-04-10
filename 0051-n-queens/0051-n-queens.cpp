class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;              // Stores all the solutions
        vector<string> board(n, string(n, '.'));    // Initialize the board with '.'
        vector<bool> columns(n, false);             // Track used columns
        vector<bool> diag1(2 * n - 1, false);        // Track used major diagonals
        vector<bool> diag2(2 * n - 1, false);        // Track used minor diagonals
        backtrack(0, n, board, columns, diag1, diag2, result);
        return result;
    }

private:
    void backtrack(int row, int n,
                   vector<string>& board,
                   vector<bool>& columns,
                   vector<bool>& diag1,
                   vector<bool>& diag2,
                   vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);  // Found a valid board, add to result
            return;
        }

        for (int col = 0; col < n; col++) {
            // Check if this column and both diagonals are free
            if (columns[col] || diag1[row + col] || diag2[row - col + n - 1])
                continue;

            // Place the queen
            board[row][col] = 'Q';
            columns[col] = diag1[row + col] = diag2[row - col + n - 1] = true;

            // Move to the next row
            backtrack(row + 1, n, board, columns, diag1, diag2, result);

            // Backtrack: remove the queen and mark unvisited
            board[row][col] = '.';
            columns[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
        }
    }
};
