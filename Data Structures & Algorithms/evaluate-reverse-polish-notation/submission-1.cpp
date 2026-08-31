class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {

            if (token != "+" && token != "-" &&
                token != "*" && token != "/") {

                st.push(stoi(token));
            }
            else {
                int t1 = st.top();
                st.pop();

                int t2 = st.top(); 
                st.pop();

                if (token == "+")
                    st.push(t2 + t1);

                else if (token == "-")
                    st.push(t2 - t1);

                else if (token == "*")
                    st.push(t2 * t1);

                else if (token == "/")
                    st.push(t2 / t1);
            }
        }

        return st.top();
    }
};