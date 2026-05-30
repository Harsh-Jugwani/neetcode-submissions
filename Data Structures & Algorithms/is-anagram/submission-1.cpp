class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> characters(26,0);
        for(auto& i : s){
            characters[i-'a']+=1;
        }
        for(auto& i : t){
            characters[i-'a']-=1;
            if(characters[i-'a'] < 0)
                return false;
        }
        return true;
    }
};
