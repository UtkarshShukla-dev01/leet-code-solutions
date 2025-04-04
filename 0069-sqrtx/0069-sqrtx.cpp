class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        long left = 1, right = x, result = 0;
        
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                left = mid + 1;
                result = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};
