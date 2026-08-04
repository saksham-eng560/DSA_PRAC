class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
for (int x : nums) cnt[x]++;

multimap<int, int, greater<int>> byFreq;
for (auto &[num, f] : cnt) byFreq.insert({f, num});

vector<int> res;
for (auto &[f, num] : byFreq) {
    if (res.size() == k) break;
    res.push_back(num);
}

return res;
    }
};
