class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> res;

        for (int k = 0; k < n; k++) {
            int i = k + 1, j = n - 1;
            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];
                if (sum < 0) {
                    i++;
                } else if (sum > 0) {
                    j--;
                } else {
                    res.insert({nums[k], nums[i], nums[j]});
                    i++; j--;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};