class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }

    void backtrack(string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(path);  // Reached the end with valid partition
            return;
        }

        for (int end = start; end < s.length(); ++end) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1)); // Choose
                backtrack(s, end + 1, path, result);              // Explore
                path.pop_back();                                  // Un-choose
            }
        }
    }

    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
};
