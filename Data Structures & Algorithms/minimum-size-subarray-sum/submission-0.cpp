class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size()==1 && nums[0]<target) return 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;int min_len = INT_MAX;
        while(r<n){
            sum+=nums[r];
            
            while(sum >= target){
                min_len = min(min_len,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};