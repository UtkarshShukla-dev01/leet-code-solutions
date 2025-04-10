class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        int m = s1.length(), n = s2.length();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return dfs(0, 0, s1, s2, s3, memo);
    }

    bool dfs(int i, int j, const string& s1, const string& s2, const string& s3, vector<vector<int>>& memo) {
        if (i == s1.length() && j == s2.length()) return true;
        if (memo[i][j] != -1) return memo[i][j];

        if (i < s1.length() && s1[i] == s3[i + j] && dfs(i + 1, j, s1, s2, s3, memo))
            return memo[i][j] = true;

        if (j < s2.length() && s2[j] == s3[i + j] && dfs(i, j + 1, s1, s2, s3, memo))
            return memo[i][j] = true;

        return memo[i][j] = false;
    }
};
