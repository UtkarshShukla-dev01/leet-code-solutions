class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;       // Stack to store indices of '(' or unmatched ')'
        stk.push(-1);         // Initialize with -1 to handle edge case for first valid substring
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);  // Push index of '('
            } else {
                stk.pop();    // Pop the matching '(' or the unmatched index
                if (stk.empty()) {
                    stk.push(i);  // Push current index to serve as a base for the next valid substring
                } else {
                    int length = i - stk.top();  // Valid length from current top
                    maxLength = max(maxLength, length);
                }
            }
        }
        return maxLength;
    }
};
