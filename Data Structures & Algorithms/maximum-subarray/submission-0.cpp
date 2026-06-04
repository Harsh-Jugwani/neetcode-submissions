class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int maxi = INT_MIN;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            maxi = max(maxi,sum);
            if(sum <= 0) 
                sum=0;
        }
        return maxi;
    }
};
