class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int maxi = 0;
        for(int right = 1; right < prices.size(); right++){
            if(prices[right] < prices[left]){
                left = right;
                continue;
            }
            else{
                maxi = max(maxi, prices[right] - prices[left]);
            }
        }

        return maxi;
    }
};
