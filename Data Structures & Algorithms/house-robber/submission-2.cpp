class Solution {
public:
    vector<int> dp = vector<int>(101,-1);
    int solve(int i, vector<int>& nums){
        if(i >= nums.size())
            return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i] + solve(i+2,nums);
        int skip = solve(i+1,nums);

        return dp[i] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return solve(0,nums);
    }
};
