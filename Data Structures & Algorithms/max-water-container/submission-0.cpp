class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int n = heights.size();
        int j = n - 1;
        int i = 0;
        
        int max_value = 0;

        while (i < j) {
            int curr_value = (j-i) * (std::min(heights[i], heights[j]));
            if (curr_value > max_value) {
                max_value = curr_value;
            }
            if (heights[i] <= heights[j]) {
                ++i;
            } else {
                --j;
            } 
        }
        return max_value;
    }
};
