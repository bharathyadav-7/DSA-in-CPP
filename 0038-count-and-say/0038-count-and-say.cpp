class Solution {
public:
    string countAndSay(int n) {

        string s = "1";

        for(int k = 1; k < n; k++) {

            string next = "";

            for(int i = 0; i < s.size(); ) {

                int count = 0;
                char ch = s[i];

                while(i < s.size() && s[i] == ch) {
                    count++;
                    i++;
                }

                next += to_string(count);
                next += ch;
            }

            s = next;
        }

        return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna