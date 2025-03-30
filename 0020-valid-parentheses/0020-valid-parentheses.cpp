class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;  // Stack to store opening brackets

        // Iterate through each character in the string
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                // Push opening brackets onto the stack
                stk.push(c);
            } else {
                // Check if the stack is empty (no corresponding opening bracket)
                if (stk.empty()) {
                    return false;
                }

                // Check for matching closing brackets
                char top = stk.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    // Pop the matching opening bracket
                    stk.pop();
                } else {
                    // Mismatch found
                    return false;
                }
            }
        }

        // The stack should be empty if all brackets were matched
        return stk.empty();
    }
};
