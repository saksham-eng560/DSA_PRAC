class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            for(int i=0;i<n+m;i++){
                nums1[i] = nums2[i];
            }
            return;
        }
        else if(n==0){
            return;
        }
        int end = n + m - 1;
        int i = m-1;
        int j = n-1;
        while(i >= 0 && j >= 0){
            if(nums1[i]>nums2[j]){
                swap(nums1[i],nums1[end]);
                i--;
            } else {
                swap(nums2[j],nums1[end]);
                j--;
            }
            end--;
        }
        while(j >= 0){
            swap(nums2[j],nums1[end]);
            j--;
            end--;
        }
    }
};