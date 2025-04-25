class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            columnNumber--; // shift to 0-indexed
            int remainder = columnNumber % 26;
            result = char('A' + remainder) + result;
            columnNumber /= 26;
        }

        return result;
    }
};
