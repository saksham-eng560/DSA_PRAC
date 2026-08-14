class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";

        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                t.push_back(tolower(s[i]));
            }
        }

        int n = t.size();

        for (int i = 0; i < n / 2; i++) {
            if (t[i] != t[n - i - 1])
                return false;
        }

        return true;
    }
};