from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Ensure nums1 is the smaller array
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        
        x, y = len(nums1), len(nums2)
        low, high = 0, x
        
        while low <= high:
            partitionX = (low + high) // 2
            partitionY = (x + y + 1) // 2 - partitionX
            
            # If partitionX is 0 it means nothing is there on left side. Use -inf for maxLeftX
            # If partitionX is length of input then there is nothing on right side. Use +inf for minRightX
            maxLeftX = float('-inf') if partitionX == 0 else nums1[partitionX - 1]
            minRightX = float('inf') if partitionX == x else nums1[partitionX]
            
            maxLeftY = float('-inf') if partitionY == 0 else nums2[partitionY - 1]
            minRightY = float('inf') if partitionY == y else nums2[partitionY]
            
            if maxLeftX <= minRightY and maxLeftY <= minRightX:
                # We have partitioned array at correct place
                if (x + y) % 2 == 0:
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0
                else:
                    return max(maxLeftX, maxLeftY)
            elif maxLeftX > minRightY:
                # We are too far on right side for partitionX. Go on left side.
                high = partitionX - 1
            else:
                # We are too far on left side for partitionX. Go on right side.
                low = partitionX + 1
        
        raise ValueError("Input arrays are not sorted.")

# Example usage
if __name__ == "__main__":
    solution = Solution()
    nums1 = [1, 3]
    nums2 = [2]
    print("Median:", solution.findMedianSortedArrays(nums1, nums2))  # Output: 2.0
    
    nums3 = [1, 2]
    nums4 = [3, 4]
    print("Median:", solution.findMedianSortedArrays(nums3, nums4))  # Output: 2.5
