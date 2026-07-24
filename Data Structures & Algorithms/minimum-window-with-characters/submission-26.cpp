class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) return "";
        
        unordered_map<char, int> freq;
        for (char c : t) freq[c]++;
        
        unordered_map<char, int> window;
        int required = freq.size(); // сколько уникальных символов нужно "закрыть"
        int formed = 0;
        
        int j = 0;
        int best_len = INT_MAX, best_start = 0;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            window[c]++;
            if (freq.count(c) && window[c] == freq[c]) {
                formed++;
            }
            
            while (formed == required) {
                if (i - j + 1 < best_len) {
                    best_len = i - j + 1;
                    best_start = j;
                }
                char lc = s[j];
                window[lc]--;
                if (freq.count(lc) && window[lc] < freq[lc]) {
                    formed--;
                }
                j++;
            }
        }
        
        return best_len == INT_MAX ? "" : s.substr(best_start, best_len);
    }
};
