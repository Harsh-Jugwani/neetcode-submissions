class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(auto&s : strs){
            string temp = "";
            vector<int> freq(26,0);
            for(auto& i : s)
                freq[i-'a']++;
            for(auto&i : freq)
                temp += ("#" + to_string(i));
            mp[temp].push_back(s);
        }
        for(auto& i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
