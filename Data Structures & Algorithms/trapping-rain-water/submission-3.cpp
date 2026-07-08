class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        vector<int> left_border(n);
        vector<int> right_border(n);

        left_border[0] = height[0];
        right_border[n-1] = height[n-1];

        for (int i = 1; i < n; ++i) {
            left_border[i] = (height[i] > left_border[i - 1])
                ? height[i]
                : left_border[i - 1];
        }

        for (int i = n-2; i >= 0; --i) {
            right_border[i] = (height[i] > right_border[i + 1])
                ? height[i]
                : right_border[i + 1];
        }

        // int i = 0;
        // int j = n - 1;

        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += (min(right_border[i], left_border[i]) - height[i]);
        }
        return sum;
    }
};
