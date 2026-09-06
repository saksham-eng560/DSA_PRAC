
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> ans;
        multiset<int> s;

        int i = 0;
        int j = 0;

        while ( j < n ) {

            while ( s.size() < k-1 ) {

                s.insert(nums[j]) ;
                j++ ;

            }

            s.insert(nums[j]) ;
            int maxi = *s.rbegin() ;
            ans.push_back(maxi) ;
            // here we erase by using s.erase(s.find(nums[i])) not only s.erase(nums[i]) bcz if we dont use s.find(nums[i]) then it removes all occurrences of nums[i]
            s.erase(s.find(nums[i])) ;
            i++ ;
            j++ ;

        }

        return ans ;
    
    }
};