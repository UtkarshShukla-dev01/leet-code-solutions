class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRow = false, firstCol = false;

        // Step 1: Check if first row or first column has any zeroes
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0) firstCol = true;

        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0) firstRow = true;

        // Step 2: Use first row and column to mark zeroes
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 3: Zero out cells based on marks
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Step 4: Zero out first row/column if needed
        if (firstCol)
            for (int i = 0; i < m; i++) matrix[i][0] = 0;

        if (firstRow)
            for (int j = 0; j < n; j++) matrix[0][j] = 0;
    }
};
