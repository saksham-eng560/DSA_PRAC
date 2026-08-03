class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;int prev = nums[0];
        // moore's voting algorihtm
        for(int i=0;i<nums.size();i++){
            if(nums[i]==prev) cnt++;
            else {cnt--;}
            if(cnt == 0) {prev = nums[i];cnt = 1;}
        }
        return prev;
    }
};