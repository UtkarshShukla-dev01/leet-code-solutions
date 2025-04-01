class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns
        
        // Iterate through the grid and update each cell with the minimum path sum
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue; // Start cell remains unchanged
                } 
                else if (i == 0) { 
                    // First row: Can only come from the left
                    grid[i][j] += grid[i][j - 1];
                } 
                else if (j == 0) { 
                    // First column: Can only come from above
                    grid[i][j] += grid[i - 1][j];
                } 
                else { 
                    // Other cells: Choose the minimum path sum from top or left
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }

        // The bottom-right cell contains the minimum path sum
        return grid[m - 1][n - 1];
    }
};
