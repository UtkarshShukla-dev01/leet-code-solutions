class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        backtrack(s, 0, "", 0, result);
        return result;
    }
    
private:
    void backtrack(string& s, int index, string current, int count, vector<string>& result) {
        if (count > 4) return;
        if (count == 4 && index == s.length()) {
            result.push_back(current.substr(0, current.length() - 1));
            return;
        }
        
        for (int len = 1; len <= 3; len++) {
            if (index + len > s.length()) break;
            string segment = s.substr(index, len);
            if ((segment[0] == '0' && segment.length() > 1) || stoi(segment) > 255) continue;
            backtrack(s, index + len, current + segment + ".", count + 1, result);
        }
    }
};
