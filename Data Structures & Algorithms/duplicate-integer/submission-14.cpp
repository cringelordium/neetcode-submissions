class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> mapp;
        for (int i = 0; i < nums.size(); ++i) {
            if (mapp.count(nums[i])) {
                return true;
            }
            mapp.insert(nums[i]);
        }
        return false;
    }
};