class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mpp1;
        unordered_map<string, char> mpp2;

        stringstream ss(s);
        string word;
        int i = 0;
        while (ss >> word) {
            if (i >= pattern.size())
                return false;
            char ch = pattern[i];
            if (mpp1.find(ch) != mpp1.end()) {
                if (mpp1[ch] != word)
                    return false;
            }
            if (mpp2.find(word) != mpp2.end()) {
                if (mpp2[word] != ch)
                    return false;
            }
            mpp1[ch] = word;
            mpp2[word] = ch;
            i++;
        }
        return i == pattern.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna