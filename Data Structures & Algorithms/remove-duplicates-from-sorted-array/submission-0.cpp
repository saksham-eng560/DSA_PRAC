class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = i+1;
        int k = 1;
        while(j < nums.size()){
            if(nums[j] == nums[i]){
                j++;
            } else {
                swap(nums[j],nums[i+1]);
                i++;j++;k++;
            }
        }
        return k;
    }
};