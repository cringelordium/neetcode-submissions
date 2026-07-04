class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        std::vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]]++;
        }
        int max_val = std::numeric_limits<int>::min();
        for (auto& [key, val] : mp) {
            if (val > max_val) {
                max_val = val;
            }
        }

        vector<vector<int>> buckets(max_val + 1);

        for (const auto& [key, value] : mp) {
            buckets[value].push_back(key);
        }

        int cnt = 0;
        for (int i = buckets.size() - 1; i > 0; --i) {
            for (int j = 0; j < buckets[i].size() && cnt < k; ++j, ++cnt) {
                res.push_back(buckets[i][j]);
            }
        }

        return res;
    }   
};
