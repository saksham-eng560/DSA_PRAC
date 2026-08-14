class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i = 0;
        int j = 0;
        string ans(n+m,',');
        int p = 0;
        while(i < n && j < m){
            ans[p] = word1[i];
            p++;
            ans[p] = word2[j];
            p++;
            j++;
            i++;
        }
        while(i < n){
            ans[p] = word1[i];
            p++;i++;
        }
        while(j < m){
            ans[p] = word2[j];
            p++;j++;
        }
        return ans;
    }
};