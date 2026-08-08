class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0] = 1;
        int pre = 0;
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++) {
            pre += nums[i];
            if(mp.find(pre-k) != mp.end()){
                cnt+=mp[pre-k];
            }
            mp[pre]++;
        }

        return cnt;
    }
};