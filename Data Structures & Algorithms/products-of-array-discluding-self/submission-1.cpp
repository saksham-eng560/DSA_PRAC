class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        map<int,pair<int,int>> mp;
        int n = nums.size();
        int suffix = 1;
        int prefix = 1;
        for(int i=0;i<n;i++) {

            mp[i].first = prefix;
            mp[n-i-1].second = suffix;

            suffix *= nums[n-i-1];
            prefix *= nums[i];
        }
        vector<int> ans(n,0);
        for(auto it : mp) {
            ans[it.first] = it.second.first * it.second.second;
        }
        return ans;
    }
};
