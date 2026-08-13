class Solution {
private:
    int maxer(vector<int> piles){
        int maxi = INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    bool hours(vector<int> &piles,int rate,int k){
        long long total_hours = 0;
        for(int i=0;i<piles.size();i++){
            total_hours += (piles[i] + (long long)rate - 1) / rate;
        }
        if(total_hours <= k) return true;
        return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int k) {
        int low = 1;
        int high = maxer(piles);

        while(low <= high){
            int mid = low + (high - low)/2;
            if(hours(piles,mid,k) == true){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
