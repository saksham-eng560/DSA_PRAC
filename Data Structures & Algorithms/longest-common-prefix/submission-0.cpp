class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<pair<int,char>,int> mp;
        int n = strs.size();
        for(int i=0;i<n;i++){
            string s = strs[i];
            for(int j=0;j<s.size();j++){
                mp[{j,s[j]}]++;
            }
        }
        string ans = "";int posn = 0;
        for(auto it : mp){
            if(it.second == n && posn == it.first.first){
                ans += it.first.second;posn++;
            }
        }
        return ans;
    }
};