class Solution {
int maxi = INT_MIN;
int ans = INT_MIN;
private:
    int summer(vector<int> nums){
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += nums[i];
        }
        return ans;
    }
    bool part(vector<int> &nums, int sum,int k){
        int part = 1;
        int curr = 0;
        maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(curr + nums[i] > sum){
                maxi = max(maxi,curr);
                curr = nums[i];
                part++;
            } else {
                curr += nums[i];
            }
        }
        if(part <= k){
            ans = max(ans,maxi);
            return true;
        }
        return false;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        //(max)min
        int low = *max_element(nums.begin(), nums.end()); //hell naw
        int high = summer(nums);
        while(low <= high){
            int mid = (low + high)/2;
            if(part(nums,mid,k) == true){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};