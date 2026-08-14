class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int a=0;a<=n-4;a++){
            for(int b=a+1;b<=n-3;b++){
                int c = b+1; int d = n-1;
                while(c<d){
                    if((long long)nums[a] + nums[b] + nums[c] + nums[d] == target){
                        vector<int> temp;
                        temp.push_back(nums[a]);
                        temp.push_back(nums[b]);
                        temp.push_back(nums[c]);
                        temp.push_back(nums[d]);
                        sort(temp.begin(),temp.end());
                        st.insert({temp});
                    }
                    if((long long)nums[a] + nums[b] + nums[c] + nums[d] < target) c++;
                    else d--;
                }
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};