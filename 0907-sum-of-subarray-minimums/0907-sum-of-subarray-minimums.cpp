class Solution {
public:
    vector<int> pse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }
    vector<int> nse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if(st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        long long MOD = 1e9 + 7;

        vector<int> left = pse(arr);
        vector<int> right = nse(arr);

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            long long l = i - left[i];
            long long r = right[i] - i;

            long long contribution =
                (long long)arr[i] * l * r;

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna