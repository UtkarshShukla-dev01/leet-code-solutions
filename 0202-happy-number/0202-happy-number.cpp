

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = getNext(n);
        }

        return n == 1;
    }

private:
    // Helper function to calculate sum of squares of digits
    int getNext(int num) {
        int total = 0;
        while (num > 0) {
            int digit = num % 10;
            total += digit * digit;
            num /= 10;
        }
        return total;
    }
};
