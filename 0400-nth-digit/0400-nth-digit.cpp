class Solution {
public:
    int findNthDigit(int n) {
        long digit = 1;
        long count = 9;
        long start = 1;

        while (digit * count < n) {
            n -= digit * count;
            digit++;
            count *= 10;
            start *= 10;
        }

        long num = start + (n - 1) / digit;
        string s = to_string(num);

        return s[(n - 1) % digit] - '0';
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna