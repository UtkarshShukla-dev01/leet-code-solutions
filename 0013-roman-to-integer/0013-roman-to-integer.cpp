class Solution {
public:
    int romanToInt(string s) {
        // Create a map for Roman numeral to integer values
        unordered_map<char, int> roman_map = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // If the current value is less than the next value, subtract the current value
            if (i < n - 1 && roman_map[s[i]] < roman_map[s[i + 1]]) {
                result -= roman_map[s[i]];
            } else {
                result += roman_map[s[i]];
            }
        }
        
        return result;
    }
};
