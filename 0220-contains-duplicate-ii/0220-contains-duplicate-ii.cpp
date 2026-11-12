class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;

        for(int i = 0; i < nums.size(); i++) {

            if(st.find(nums[i]) != st.end()) {
                return true;
            }

            st.insert(nums[i]);

            if(st.size() > k) {
                st.erase(nums[i-k]);
            }
        }

        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna