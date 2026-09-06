class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int n = s2.size();

        if(k > n) return false;

        vector<int> need(26, 0);
        vector<int> curr(26, 0);

        for(char c : s1) {
            need[c - 'a']++;
        }

        int l = 0;
        int r = k - 1;

        for(int i = l; i <= r; i++) {
            curr[s2[i] - 'a']++;
        }

        while(r < n) {
            if(curr == need) return true;

            r++;

            if(r == n) break;

            curr[s2[r] - 'a']++;

            curr[s2[l] - 'a']--;
            l++;
        }

        return false;
    }
};