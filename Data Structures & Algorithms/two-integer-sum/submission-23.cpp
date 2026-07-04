class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        std::unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); ++i) {
            int find = target - nums[i];

            if (mp.count(find)) {
                return {mp[find], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
