class Solution {
public:

int maxfreq(map<char,int> mp){
        int maxFreq = 0;

    for(auto &it : mp){
        maxFreq = max(maxFreq, it.second);
    }
return maxFreq;
}
    int characterReplacement(string s, int k) {
        int l=0;int r=0;
        int max_freq = 0;
        int n = s.size();
        map<char,int> mp;
        int len = 0;

        while(r < n) {
            mp[s[r]]++;
            max_freq = maxfreq(mp);
            while( (r-l+1)-max_freq > k){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            if((r-l+1) - max_freq <= k){
                len = max(len,r-l+1);
            }
            r++;
        }
        return len;
    }
};