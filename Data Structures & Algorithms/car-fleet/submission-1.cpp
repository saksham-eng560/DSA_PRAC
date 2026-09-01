class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, double>> cars;

        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Position ascending
        sort(cars.begin(), cars.end());

        stack<double> st;

        st.push(cars[n - 1].second);

        int fleet = 1;

        for (int i = n - 2; i >= 0; i--) {

            while (!st.empty() && st.top() < cars[i].second) {
                st.pop();
            }

            if (st.empty()) {
                fleet++;
            }

            st.push(cars[i].second);
        }

        return fleet;
    }
};