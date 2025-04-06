class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;

        // Step 1: Sort intervals based on start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Iterate through intervals and merge overlapping ones
        for (const auto& interval : intervals) {
            // If merged is empty or no overlap, simply add the interval
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // Overlapping interval: update the end time
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};
