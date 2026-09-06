class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;int r = 0;
        map<char,int> mp;
        int min_len = INT_MAX;
        int indx = -1;int cnt = 0;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }

        while(r < s.size()){
            if(mp[s[r]]>0){
                mp[s[r]]--;
                cnt++;
            } else {
                mp[s[r]]--;
            }
            while(cnt==t.size()){
                if(min_len > r-l+1){
                    min_len = r-l+1;indx = l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return indx == -1? "" : s.substr(indx,min_len);
    }
};