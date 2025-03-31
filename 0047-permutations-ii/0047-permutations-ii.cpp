class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        unordered_set<int> seen;
        for (int i = start; i < nums.size(); ++i) {
            if (seen.find(nums[i]) != seen.end()) continue;
            seen.insert(nums[i]);
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, result);
            swap(nums[start], nums[i]);
        }
    }
};
