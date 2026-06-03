class Solution {
public:

    int characterReplacement(string s, int k) {
        int left = 0;
        int maxi = 0;
        unordered_map<char,int> mp;
        int max_freq = 0;
        for(int right = 0; right < s.size(); right++){
            mp[s[right]]++;
            max_freq = max(max_freq,mp[s[right]]);
            
            while((right-left+1) - max_freq > k){
                mp[s[left]]--;
                left++;
            }
            maxi = max(maxi,right-left+1);
        }
        return maxi;
    }
};
