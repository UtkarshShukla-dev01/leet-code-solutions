class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result <<= 1;               // Make space for the new bit in result
            result |= (n & 1);          // Add the least significant bit of n to result
            n >>= 1;                    // Shift n to the right to process the next bit
        }
        return result;
    }
};
