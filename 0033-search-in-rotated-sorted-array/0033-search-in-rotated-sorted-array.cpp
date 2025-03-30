class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // Check if the left part is sorted
            if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;  // Search in the left half
                } else {
                    left = mid + 1;   // Search in the right half
                }
            } 
            // Otherwise, the right part is sorted
            else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;   // Search in the right half
                } else {
                    right = mid - 1;  // Search in the left half
                }
            }
        }
        
        return -1;  // Target not found
    }
};
