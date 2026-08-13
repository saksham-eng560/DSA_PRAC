class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size()==2){
            if(nums[0] > nums[1]) return nums[1];
            else return nums[0];
        }
        int low = 0;
        int high = nums.size()-1;
        int mini = INT_MAX;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[low] <= nums[mid]){
                mini = min(mini,nums[low]); //left sorted
                low = mid + 1;
            } else {
                mini = min(mini,nums[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }
};
