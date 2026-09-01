class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int x : asteroids) {

            if (x > 0) {
                st.push(x);
            }
            else {
                bool alive = true;

                while (!st.empty() && st.top() > 0 && st.top() < -x) {
                    st.pop();
                }

                if (!st.empty() && st.top() > 0) {
                    if (st.top() == -x) {
                        st.pop();     
                    }
                    alive = false;
                }

                if (alive) {
                    st.push(x);
                }
            }
        }

        vector<int> ans(st.size());

        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};