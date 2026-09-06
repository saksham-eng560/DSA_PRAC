class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        multiset<pair<int, int>> st;

        for(int val : arr) {
            st.insert({abs(val - x), val});
        }

        vector<int> ans;

        for(auto it : st) {
            if(ans.size() == k) break;
            ans.push_back(it.second);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};