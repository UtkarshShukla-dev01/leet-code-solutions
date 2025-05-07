class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> pos;
        vector<int> rowCount(m, 0), colCount(n, 0);

        // Map each value to its matrix coordinates
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[mat[i][j]] = {i, j};
            }
        }

        // Traverse the array and paint the cells
        for (int k = 0; k < arr.size(); ++k) {
            auto [row, col] = pos[arr[k]];
            if (++rowCount[row] == n || ++colCount[col] == m) {
                return k;
            }
        }
        return -1;
    }
};
