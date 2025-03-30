class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;  // Pointer to track the number of elements not equal to val

        // Iterate through the array
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                // If the current element is not equal to val, place it at index k
                nums[k] = nums[i];
                k++;  // Increment k as we've added a valid element
            }
        }

        // k is the number of elements not equal to val
        return k;
    }
};
