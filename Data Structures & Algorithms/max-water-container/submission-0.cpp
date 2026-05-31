class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxi = INT_MIN;
        while(left < right){
            int temp = 0;
            if(heights[left] <= heights[right]){
                temp = heights[left] * (right-left);
                left++;
            }
            else{
                temp = heights[right] * (right-left);
                right--;
            }
            maxi = max(maxi,temp);
        }
        return maxi;
    }
};
