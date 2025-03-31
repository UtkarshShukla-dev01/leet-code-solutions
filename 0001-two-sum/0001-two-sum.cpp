class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map; // To store the number and its index
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i}; // Return indices of the two numbers
            }
            num_map[nums[i]] = i; // Store the index of the current number
        }
        return {}; // This line will never be reached since there's exactly one solution
    }
};
