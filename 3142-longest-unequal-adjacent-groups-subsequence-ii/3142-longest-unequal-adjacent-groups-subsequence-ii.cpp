class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1), prev(n, -1);
        int maxLength = 1, lastIndex = 0;

        // Check Hamming distance
        auto hammingDistance = [](const string &a, const string &b) {
            int dist = 0;
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] != b[i]) ++dist;
            }
            return dist;
        };

        // Loop through all pairs of words
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && words[i].length() == words[j].length() && hammingDistance(words[i], words[j]) == 1) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct the sequence
        vector<string> result;
        while (lastIndex != -1) {
            result.push_back(words[lastIndex]);
            lastIndex = prev[lastIndex];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
