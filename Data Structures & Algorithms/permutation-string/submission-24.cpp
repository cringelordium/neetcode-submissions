class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26);
        vector<int> need(26);
        
        for (auto& c : s1) {
            freq[c - 'a']++;
        }

        int i = 0;
        int j = 0;
        int m = s1.size();
        int n = s2.size();

        while (i < n) {
            if (freq[s2[i] - 'a']) {
                need[s2[i] - 'a']++;
            } else {
                ++i;
                while (freq[s2[j] - 'a']) {
                    need[s2[j] - 'a']--;   
                    j++;
                }
                j = i;
                continue;
            }
            while (i-j+1 > m) {
                need[s2[j] - 'a']--;   
                j++;    
            }
            if (need == freq) {
                return true;
            }
            ++i;
        }
        return false;
    }
};
