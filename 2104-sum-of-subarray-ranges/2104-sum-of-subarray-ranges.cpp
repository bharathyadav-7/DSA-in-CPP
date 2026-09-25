class Solution {
public:

    // Previous Smaller
    vector<int> pse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }


    // Next Smaller
    vector<int> nse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            if(st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }


    // Previous Greater
    vector<int> pge(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }


    // Next Greater
    vector<int> nge(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            if(st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }


    long long sumMin(vector<int>& nums) {

        int n = nums.size();

        vector<int> left = pse(nums);
        vector<int> right = nse(nums);

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            long long l = i - left[i];
            long long r = right[i] - i;

            ans += (long long)nums[i] * l * r;
        }

        return ans;
    }


    long long sumMax(vector<int>& nums) {

        int n = nums.size();

        vector<int> left = pge(nums);
        vector<int> right = nge(nums);

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            long long l = i - left[i];
            long long r = right[i] - i;

            ans += (long long)nums[i] * l * r;
        }

        return ans;
    }


    long long subArrayRanges(vector<int>& nums) {

        long long maximum = sumMax(nums);
        long long minimum = sumMin(nums);

        return maximum - minimum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna