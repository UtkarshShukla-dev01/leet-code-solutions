class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLength = 0;
        
        // Expand around center helper function
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            int len = right - left - 1; // Length of palindrome
            if (len > maxLength) {
                maxLength = len;
                start = left + 1;
            }
        };
        
        for (int i = 0; i < s.length(); i++) {
            expandAroundCenter(i, i);     // Odd-length palindrome
            expandAroundCenter(i, i + 1); // Even-length palindrome
        }
        
        return s.substr(start, maxLength);
    }
};
