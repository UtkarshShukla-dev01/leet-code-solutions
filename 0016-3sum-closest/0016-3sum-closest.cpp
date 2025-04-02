#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end()); // Step 1: Sort the array
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2]; // Initial assumption

        for (int i = 0; i < n - 2; i++) { // Step 3: Fix one element
            int left = i + 1, right = n - 1;
            while (left < right) { 
                int currentSum = nums[i] + nums[left] + nums[right];

                // Update closestSum if currentSum is closer to target
                if (std::abs(target - currentSum) < std::abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    left++;  // Move left pointer to increase sum
                } else if (currentSum > target) {
                    right--; // Move right pointer to decrease sum
                } else {
                    return currentSum; // Exact match found
                }
            }
        }
        return closestSum;
    }
};
