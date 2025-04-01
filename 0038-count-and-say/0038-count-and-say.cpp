class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";  // Base case
        
        string result = "1";  // Starting sequence
        
        for (int i = 2; i <= n; i++) {
            string current = "";
            int count = 1;
            
            for (int j = 1; j < result.size(); j++) {
                if (result[j] == result[j - 1]) {
                    count++;  // Increment count if the same character repeats
                } else {
                    current += to_string(count) + result[j - 1];  // Append count and digit
                    count = 1;  // Reset count
                }
            }
            
            current += to_string(count) + result.back();  // Add last processed character
            result = current;  // Update result for next iteration
        }
        
        return result;
    }
};
