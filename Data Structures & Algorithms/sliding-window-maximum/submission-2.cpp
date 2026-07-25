class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;
        int end;

        for (int i = 0; i < nums.size(); ++i) {
            std::priority_queue<int> q;
            for (int j = i; j < i+k; ++j) {
                if (j == nums.size()) {
                    end = j;
                    break;
                }
                q.push(nums[j]); 
            }
            if (end == nums.size()) return res;

            int max_el = q.top();
            res.push_back(max_el);
        }
        return res;
    }
};
