class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       int l = 0;
       int r = people.size()-1;
       int boats = 0;
       sort(people.begin(),people.end());
       int curr = 0;
       while(people[r] > limit){
        r--;boats++;
       }
       while(l <= r){
        curr = people[l] + people[r];
        if(curr == limit){
            boats++;l++;r--;curr = 0;
        } else if(curr > limit){
            boats++;r--;curr = 0;
        } else {
            l++;r--;boats++;
        }
       }
       return boats; 
    }
};