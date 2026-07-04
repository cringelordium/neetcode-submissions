class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        for (char c : t) {
            if (--counter[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
