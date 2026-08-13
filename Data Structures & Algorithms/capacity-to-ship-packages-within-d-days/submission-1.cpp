class Solution {
private:
    int summer(vector<int> nums){
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
        }
        return ans;
    }
    bool isPossible(vector<int> &nums,int cap,int target){
        if (cap < *max_element(nums.begin(), nums.end())) return false;
        int days = 1;int wt = 0;
        for(int i=0;i<nums.size();i++){
            if(wt + nums[i] > cap){
                wt = nums[i];
                days++;
            } else {
                wt += nums[i];
            }
        }
        if(days <= target) return true;
        return false;
    }
public:
    int shipWithinDays(vector<int>& nums, int target) {
        int low = 0;
        int high = summer(nums);

        while(low <= high){
            int mid = (low + high)/2;
            if(isPossible(nums,mid,target) == true){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};