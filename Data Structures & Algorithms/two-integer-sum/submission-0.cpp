class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){

            int need = target-nums[i];
            if(mp.find(need) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[need]);
                break;
            }
            mp[nums[i]]=i;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
