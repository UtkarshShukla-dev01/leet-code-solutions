class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> result(m + n, 0); // Maximum length of result is m + n

        // Multiply each digit and add the results
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0'); // Multiply digits
                int sum = mul + result[i + j + 1];           // Add to existing value
                result[i + j + 1] = sum % 10;                // Current digit
                result[i + j] += sum / 10;                   // Carry to the next position
            }
        }

        // Convert result to string, skipping leading zeros
        string product;
        for (int num : result) {
            if (!(product.empty() && num == 0)) {
                product += to_string(num);
            }
        }

        return product.empty() ? "0" : product;
    }
};
