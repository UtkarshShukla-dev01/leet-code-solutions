class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the overflow case (since -2147483648 / -1 would overflow)
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;  // Return 2147483647
        }
        
        // Determine the sign of the result
        bool negative = (dividend < 0) != (divisor < 0);
        
        // Work with positive values for simplicity
        long long dividendL = abs((long long)dividend);
        long long divisorL = abs((long long)divisor);
        
        long long quotient = 0;
        
        // Perform the division by subtracting the divisor (shifted) from dividend
        while (dividendL >= divisorL) {
            long long tempDivisor = divisorL, multiple = 1;
            
            // Increase the divisor to the largest multiple of divisor <= dividend
            while (dividendL >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            
            // Subtract the largest multiple and update the quotient
            dividendL -= tempDivisor;
            quotient += multiple;
        }
        
        // Apply the sign to the quotient
        if (negative) {
            quotient = -quotient;
        }
        
        // Ensure the result is within the 32-bit signed integer range
        if (quotient < INT_MIN) {
            return INT_MIN;
        }
        if (quotient > INT_MAX) {
            return INT_MAX;
        }
        
        return quotient;
    }
};
