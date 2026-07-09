class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;

        int curr_min = std::numeric_limits<int>::max(); ; 
        int pr_max = 0; 

        for (i; i < prices.size(); ++i) {
            curr_min = min(curr_min, prices[i]);
            pr_max = max(pr_max, prices[i] - curr_min);
        }

        return pr_max;
    }
};
