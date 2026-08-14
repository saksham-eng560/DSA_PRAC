class Solution {
public:
    int maxArea(vector<int>& heights) {
        int water = INT_MIN;
        int l = 0;
        int r = heights.size() - 1;

        while(l < r){
            water = max(water,(min(heights[l],heights[r])*(r-l)));
            if(heights[l] < heights[r]){
                l++;
            } else {
                r--;
            }
        }
        return water;
    }
};
