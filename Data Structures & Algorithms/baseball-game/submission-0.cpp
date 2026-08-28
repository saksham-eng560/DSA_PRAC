class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int> st;

        for(int i = 0; i < n; i++){
            char x = operations[i][0];

            if((x >= '0' && x <= '9') || x == '-'){
                st.push(stoi(operations[i]));
            }
            else if(x == '+'){
                int t1 = st.top();
                st.pop();

                int t2 = st.top();

                st.push(t1);
                st.push(t1 + t2);
            }
            else if(x == 'D'){
                int t1 = st.top();
                st.push(2 * t1);
            }
            else {
                st.pop();
            }
        }

        int score = 0;

        while(!st.empty()){
            int temp = st.top();
            st.pop();
            score += temp;
        }

        return score;
    }
};