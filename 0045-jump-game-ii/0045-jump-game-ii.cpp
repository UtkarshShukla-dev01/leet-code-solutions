class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, farthest = 0, currEnd = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]); // Update the farthest we can reach
            
            if (i == currEnd) { // If we reach the end of the current jump
                jumps++;  
                currEnd = farthest; // Update the current jump boundary
            }
        }
        
        return jumps;
    }
};
