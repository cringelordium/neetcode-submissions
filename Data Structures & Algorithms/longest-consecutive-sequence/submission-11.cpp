class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;

    for (auto& el : nums) {
        us.insert(el);
    }

    if (us.size() == 1) {
        return 1;
    }


    set<int> ret;
    for (const int& el : us) {
        if (!us.count(el-1)) {
            ret.insert(el);
        }
    }

    int cur_cnt = 0;
    int max_cnt = 0;
    auto it = ret.begin();
    int start = *it;
    for (int start : ret) {
        int cur = start;
        int len = 1;

        while (us.count(cur + 1)) {
            cur++;
            len++;
        }

        max_cnt = max(max_cnt, len);
    }

    return max_cnt;
    }
};
