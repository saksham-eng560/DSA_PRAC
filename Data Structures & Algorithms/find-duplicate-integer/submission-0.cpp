using namespace std;
class Solution {
public:

    int findDuplicate(vector<int>& nums) {
                int cnt = 0;
        map<int,int> hash;
        for(int i=0; i< nums.size();i++){
            hash[nums[i]]++;
        }
for(auto it : hash) {
    if(it.second>=2){
        return it.first;
    }
}
return 0;
    }
};