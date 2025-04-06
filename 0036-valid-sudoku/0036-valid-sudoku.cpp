class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Create sets for rows, columns, and boxes
        unordered_set<char> rows[9], cols[9], boxes[9];

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char val = board[i][j];
                if (val == '.') continue; // Skip empty cells

                // Check row
                if (rows[i].count(val)) return false;
                rows[i].insert(val);

                // Check column
                if (cols[j].count(val)) return false;
                cols[j].insert(val);

                // Check box
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (boxes[boxIndex].count(val)) return false;
                boxes[boxIndex].insert(val);
            }
        }

        return true;
    }
};
