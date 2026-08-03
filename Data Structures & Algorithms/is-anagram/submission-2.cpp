class Solution {
public:
    bool isAnagram(string s, string t) {
        // better solution
        if(s.size() != t.size()) return false;
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(mp.find(t[i]) == mp.end()) return false;
            else {
                mp[t[i]]--;
                if(mp[t[i]] == 0) mp.erase(t[i]);
            }
        }
        return true;

        // sort both and then equal
    }
};
