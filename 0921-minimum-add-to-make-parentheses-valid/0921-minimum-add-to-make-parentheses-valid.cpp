class Solution {
public:
    int minAddToMakeValid(string s) {
        vector<char> stack;
        for (char c : s) {
            if (!stack.empty() && stack.back() == '(' && c == ')') {
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        return stack.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna