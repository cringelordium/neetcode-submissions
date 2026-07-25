class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;
        deque<pair<int,int>> dq;

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            // убираем элементы, которые уже меньше нового
            while (!dq.empty() && dq.back().first < nums[right]) {
                dq.pop_back();
            }

            // добавляем новый элемент справа
            dq.push_back({nums[right], right});


            // убираем элементы, которые вышли из окна
            if (dq.front().second < left) {
                dq.pop_front();
            }


            // окно полностью сформировано
            if (right >= k - 1) {
                res.push_back(dq.front().first);
                left++;
            }
        }

        return res;
    }
};