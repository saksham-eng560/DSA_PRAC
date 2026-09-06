class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (mp[nums[r]] > 0)
                return true;

            mp[nums[r]]++;

            if (r - l >= k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
        }

        return false;
    }
};