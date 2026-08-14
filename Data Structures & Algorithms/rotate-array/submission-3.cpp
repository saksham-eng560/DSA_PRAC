class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size()){
            k = k % nums.size();
        }
        k = nums.size()-k;
        reverse(nums.begin(),nums.begin() + k);
        reverse(nums.begin()+k,nums.end());
        
        return reverse(nums.begin(),nums.end());

    }
};