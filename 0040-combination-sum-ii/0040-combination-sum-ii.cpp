class Solution {
public:
    void findCombinations(int index, int target, vector<int>& candidates, vector<vector<int>>& result, vector<int>& current) {
        if (target == 0) {  // If target is met, add the combination
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;  // Skip duplicates
            if (candidates[i] > target) break;  // Stop further recursion if number exceeds target
            
            current.push_back(candidates[i]);  // Include number
            findCombinations(i + 1, target - candidates[i], candidates, result, current);  // Move to next index
            current.pop_back();  // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates easily
        findCombinations(0, target, candidates, result, current);
        return result;
    }
};
