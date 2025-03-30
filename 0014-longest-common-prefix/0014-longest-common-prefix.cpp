class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Start with the prefix being the first string
        string prefix = strs[0];
        
        // Compare the prefix with each string in the array
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            // Find the common part between the prefix and the current string
            while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
                j++;
            }
            // Update the prefix to be the common part found
            prefix = prefix.substr(0, j);
            // If at any point the prefix becomes empty, return an empty string
            if (prefix.empty()) return "";
        }
        
        return prefix;
    }
};
