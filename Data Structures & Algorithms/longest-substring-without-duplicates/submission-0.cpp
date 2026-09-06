class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    vector<int> arr(256, -1);
       int l = 0;
       int r = 0;
       int maxi = 0;
       int len = 0;
       int n = s.size();
       while(r < n){
        int asc = s[r];
        if(arr[asc]==-1){
            arr[asc]=r;
       
        } else {
            if(arr[asc]<l){
                arr[asc]=r;
            } else {
                  l = arr[asc]+1;
                
            arr[asc]=r;
          
            }
        }
        len = r-l+1;
            maxi = max(len,maxi);
        r++;
       }
       return maxi;
    }
};