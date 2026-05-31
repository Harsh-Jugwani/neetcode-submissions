class Solution {
   public:
    int n;
    vector<vector<int>> dp;
    
    int solve(int i, int prev, vector<int>& nums) {
        if (i >= n) return 0;
        if(dp[i][prev +1] != -1) return dp[i][prev+1];
        int take= 0;
        int notTake = 0;
        if (prev == -1 || nums[prev] < nums[i])
            take = max(1 + solve(i + 1, i, nums), solve(i + 1, prev, nums));
        else
            notTake = solve(i + 1, prev, nums);
        return dp[i][prev+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        if (n == 1) return 1;
        dp.resize(n, vector<int>(n+1,-1));
        return solve(0, -1, nums);
    }
};
