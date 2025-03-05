class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0; // Tracks the maximum index we can reach
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (i > maxReach) return false; // If 'i' is beyond max reachable index, we can't continue
            maxReach = max(maxReach, i + nums[i]); // Update max reach
            
            if (maxReach >= n - 1) return true; // If we can reach the last index, return true
        }
        
        return false;
    }
};
