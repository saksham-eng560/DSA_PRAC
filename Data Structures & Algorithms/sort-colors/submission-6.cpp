class Solution {
public:
    void sortColors(vector<int>& nums) {
        //O(n)
        int low = 0;
        int high = nums.size()-1;
        int mid = 0;
        while(mid <= high){
            if(nums[mid] == 0){
                //swap low and mid and low++
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                low++;mid++;
            }
            else if(nums[mid] == 1) mid++;
            else if(nums[mid] == 2){
                //swap mid and high then high--
                int temp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = temp;
                high--;
            }
        }
    }
};