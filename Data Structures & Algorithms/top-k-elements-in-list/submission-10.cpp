class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        std::vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]]++;
        }
        vector<int> arr;
        for (auto& [key, val] : mp) {
            arr.push_back(key);
        }

        sort(arr.begin(), arr.end(), [&](int a, int b){
            return mp[a] > mp[b];
        });

        arr.resize(k);
        return arr;
    }   
};
