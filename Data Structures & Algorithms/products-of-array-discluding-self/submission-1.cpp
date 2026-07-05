class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> suff(nums.size());
        res[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            res[i] = nums[i-1] * res[i-1];     
        }
        suff[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            suff[i] = nums[i+1] * suff[i+1];     
        }        

        for (int i = 0; i < nums.size(); ++i) {
            res[i] *= suff[i];
        }

        return res;
    }
};
