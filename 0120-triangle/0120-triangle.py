class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # Start from the last row
        dp = triangle[-1][:]  # Make a copy of the last row

        # Move upward from the second-last row to the top
        for row in range(len(triangle) - 2, -1, -1):
            for col in range(len(triangle[row])):
                # Update each element to be the min path sum of its two children
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1])

        return dp[0]  # The top element holds the minimum path sum
