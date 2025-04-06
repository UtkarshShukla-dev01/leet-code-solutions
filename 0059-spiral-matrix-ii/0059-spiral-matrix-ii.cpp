class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n)); // Create n x n matrix
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int num = 1;

        while (left <= right && top <= bottom) {
            // Move left to right
            for (int j = left; j <= right; ++j)
                matrix[top][j] = num++;
            top++;

            // Move top to bottom
            for (int i = top; i <= bottom; ++i)
                matrix[i][right] = num++;
            right--;

            // Move right to left
            if (top <= bottom) {
                for (int j = right; j >= left; --j)
                    matrix[bottom][j] = num++;
                bottom--;
            }

            // Move bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    matrix[i][left] = num++;
                left++;
            }
        }

        return matrix;
    }
};
