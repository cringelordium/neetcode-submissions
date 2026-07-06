class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        if (n < 3) return res;

        for (int i = 0; i < n; ++i) {

            // дедупликация i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];
            int k = i + 1;
            int j = n - 1;

            while (k < j) {
                int sum = nums[k] + nums[j];

                if (sum < target) {
                    ++k;
                } 
                else if (sum > target) {
                    --j;
                } 
                else {
                    res.push_back({nums[i], nums[k], nums[j]});

                    ++k;
                    --j;

                    // дедупликация после нахождения ответа
                    while (k < j && nums[k] == nums[k - 1]) ++k;
                    while (k < j && nums[j] == nums[j + 1]) --j;
                }
            }
        }

        return res;
    }
};