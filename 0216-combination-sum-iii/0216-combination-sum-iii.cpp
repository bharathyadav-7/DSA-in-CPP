class Solution {
public:
    void func(int start, int k, int sum,
              vector<int>& ds, vector<vector<int>>& ans) {

        if (k == 0) {
            if (sum == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if (sum < 0) {
            return;
        }

        for (int i = start; i <= 9; i++) {

            ds.push_back(i);

            func(i + 1, k - 1, sum - i, ds, ans);

            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        func(1, k, n, ds, ans);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna