class Solution {
public:
void func(int ind,int xr,vector<int> &nums,int &ans){
    int n=nums.size();
    if(ind==n){
        ans += xr;
        return;
    }
    func(ind+1,xr^nums[ind],nums,ans);
    func(ind+1,xr,nums,ans);
}
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        func(0,0,nums,ans);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna