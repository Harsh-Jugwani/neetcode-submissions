class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        priority_queue<int> q;
        for(auto i : nums)
            q.push(i);
        int maxi = 1;
        int cnt = 1;
        int last = q.top();
        q.pop();
        while(!q.empty()){
            int ele = q.top();
            q.pop();
            if(ele == last)
                continue;
            if(ele == last - 1){
                cnt++;
            }
            else{
                cnt = 1;
            }
            maxi = max(maxi,cnt);
            last  = ele;     
        }
        return maxi;

    }
};
