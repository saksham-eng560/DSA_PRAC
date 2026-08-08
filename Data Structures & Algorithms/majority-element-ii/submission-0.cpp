class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1 = 0, el2 = 1;
        int cn1 = 0, cn2 = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == el1) {
                cn1++;
            }
            else if(nums[i] == el2) {
                cn2++;
            }
            else if(cn1 == 0) {
                el1 = nums[i];
                cn1 = 1;
            }
            else if(cn2 == 0) {
                el2 = nums[i];
                cn2 = 1;
            }
            else {
                cn1--;
                cn2--;
            }
        }
        cn1 = 0;
        cn2 = 0;

        for(int x : nums) {
            if(x == el1) cn1++;
            else if(x == el2) cn2++;
        }

        vector<int> ans;

        if(cn1 > nums.size() / 3)
            ans.push_back(el1);

        if(cn2 > nums.size() / 3)
            ans.push_back(el2);

        return ans;
    }
};