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
            need[s2[i] - 'a']++;

            if (i-j+1 > m) {
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
