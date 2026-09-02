class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (s[i] != ']') {
                st.push(s[i]);
            }
            else {
                string t = "";

                while (!st.empty() && st.top() != '[') {
                    t += st.top();
                    st.pop();
                }
                st.pop();

                reverse(t.begin(), t.end());

                string num = "";

                while (!st.empty() && isdigit(st.top())) {
                    num += st.top();
                    st.pop();
                }

                reverse(num.begin(), num.end());

                int times = stoi(num);

                for (int j = 0; j < times; j++) {
                    for (char c : t) {
                        st.push(c);
                    }
                }
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};