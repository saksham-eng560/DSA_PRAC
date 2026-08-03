class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == val){
                for(int j=i+1;j<nums.size();j++){
                    if(nums[j] != val){
                        //swap
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                        k++;
                        break;
                    }
                }
            } else {k++;}
        }
        return k;
    }
};