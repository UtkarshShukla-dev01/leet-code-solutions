class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        // dp[i][j] = min operations to convert word1[0..i-1] to word2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base cases: one string is empty
        for (int i = 0; i <= m; i++) dp[i][0] = i;  // delete all from word1
        for (int j = 0; j <= n; j++) dp[0][j] = j;  // insert all to word1

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // characters match, no operation needed
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // choose the best among insert, delete, replace
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],     // delete
                        dp[i][j - 1],     // insert
                        dp[i - 1][j - 1]  // replace
                    });
                }
            }
        }

        return dp[m][n];
    }
};
