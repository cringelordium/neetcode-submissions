class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_cnt = 0;
        int j = 0;
        unordered_set<int> st;
        
        for (int i = 0; i < s.size(); ++i) {
            st.insert(s[i]);
        }

        if (st.size() == s.size()) return s.size();
        else st.clear();

        for (int i = 0; i < s.size(); ++i) {
            while (st.contains(s[i])) {
                st.erase(s[j]);
                ++j;
            }
            st.insert(s[i]);
            int size = st.size();
            max_cnt = max(max_cnt, size);
        }
        return max_cnt;
    }
};