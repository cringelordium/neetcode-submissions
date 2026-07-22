class Solution {
public:
    int characterReplacement(string s, int k) {
        if (k == s.size()) {
            return s.size();
        }

        int i = 0;
        int j = 0;
        
        std::unordered_map<int, int> mp;
        int max_freq = 0;
        int longest = 0;

        while (i < s.size()) {

            mp[s[i]]++;
            max_freq = max(max_freq, mp[s[i]]);

            while ((i-j+1) - max_freq > k) {
                mp[s[j]]--;
                j++;
            }
            longest = max(i-j+1, longest);
            i++;
        }
        return longest;
    }
};
