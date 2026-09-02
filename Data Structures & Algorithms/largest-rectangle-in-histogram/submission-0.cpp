class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<int> st;
        int i = 1;
        int pse = 0;
        int nse = 0;
        int curr = 0;
        int area = 0;
        int maxi = 0;
        st.push(0);
        while(i<nums.size()){
            if(nums[i]>nums[st.top()]){
                st.push(i);
            } else {
                while(!st.empty() && nums[i]<=nums[st.top()]) {
                nse = i;
                curr = nums[st.top()];
                st.pop();
                if(st.empty()){pse = -1;} else {pse = st.top();}
                area = curr*(nse-pse-1);
                maxi = max(area,maxi); 
            }
            st.push(i);
            }
            i++;
        }
        while(!st.empty()){
            nse = nums.size();
            curr = nums[st.top()];st.pop();
            if(st.empty()){pse = -1;} else {pse = st.top();}
            area = curr*(nse-pse-1);
                maxi = max(area,maxi);
        }
        return maxi;
    }
};