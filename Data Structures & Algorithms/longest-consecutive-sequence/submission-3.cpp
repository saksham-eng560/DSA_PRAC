class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;

        int maxi = 1;
        map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]] = i;
            int cnt = 1;
            int key = nums[i];

            while(mp.find(key-1) != mp.end()) {
                cnt++;
                maxi = max(maxi,cnt);
                key--;
            }
            cnt = 1;
            while(mp.find(key+1) != mp.end()) {
                cnt++;
                maxi = max(maxi,cnt);
                key++;
            }
        }
        return maxi;
    }
};
