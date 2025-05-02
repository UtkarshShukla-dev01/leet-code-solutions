class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> force(n, 0);
        
        // Step 1: Left to Right - applying 'R' forces
        int f = 0;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R') {
                f = n; // max force
            } else if (dominoes[i] == 'L') {
                f = 0; // reset force
            } else {
                f = max(f - 1, 0); // decay force
            }
            force[i] += f;
        }
        
        // Step 2: Right to Left - applying 'L' forces
        f = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') {
                f = n;
            } else if (dominoes[i] == 'R') {
                f = 0;
            } else {
                f = max(f - 1, 0);
            }
            force[i] -= f;
        }
        
        // Step 3: Build the result
        string result;
        for (int f : force) {
            if (f > 0) result += 'R';
            else if (f < 0) result += 'L';
            else result += '.';
        }
        
        return result;
    }
};
