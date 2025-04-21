class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Place each number in its correct position if possible
        for (int i = 0; i < n; ++i) {
            // Keep swapping until nums[i] is in the correct position,
            // or it's out of range
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: Find the first location where the number is incorrect
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all numbers from 1 to n are present
        return n + 1;
    }
};
