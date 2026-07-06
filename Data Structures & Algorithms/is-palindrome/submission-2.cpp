class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        std::transform(s.begin(), s.end(), s.begin(),
               [](unsigned char c) { return std::tolower(c); });

        while (i <= j) {
            if (!std::isalnum(static_cast<unsigned char>(s[i]))) {
                ++i;
                continue;
            }
            if (!std::isalnum(static_cast<unsigned char>(s[j]))) {
                --j;
                continue;
            }
            
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};
