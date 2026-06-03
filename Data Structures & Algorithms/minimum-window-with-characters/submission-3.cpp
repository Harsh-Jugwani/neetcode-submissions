class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        if(s == t) return s;
        unordered_map<char,int> mp1,mp2;
        for(auto&c : t){
            mp1[c]++;
        }
        int left = 0;
        int have = 0;
        int need = mp1.size();
        int mini = INT_MAX;
        int idx = -1;
        for(int right = 0; right < s.size(); right++){
            if(mp1.count(s[right])) mp2[s[right]]++;
            if(mp1.count(s[right]) && mp2[s[right]] == mp1[s[right]]){
                have++;
            }
            while(have == need){
                if(mini > right-left+1){
                    mini = right-left+1;
                    idx = left;
                }
                if(mp1.count(s[left])) mp2[s[left]]--;
                if(mp1.count(s[left]) && mp2[s[left]] < mp1[s[left]]){
                    have--;
                }
                left++;
            }
            
        }
        return mini == INT_MAX ? "" : s.substr(idx,mini);
    }
};
