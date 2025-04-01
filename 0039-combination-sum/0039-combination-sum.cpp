class Solution {
public:
    void findCombinations(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& current, int index) {
        if (target == 0) {  // If the target is met, add the current combination
            result.push_back(current);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;  // Skip if the number exceeds the target
            
            current.push_back(candidates[i]);  // Include the number
            findCombinations(candidates, target - candidates[i], result, current, i);  // Recursively explore
            current.pop_back();  // Backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        findCombinations(candidates, target, result, current, 0);
        return result;
    }
};
