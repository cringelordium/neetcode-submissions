class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (auto& s : strs) {
            int len = s.size();
            res += to_string(len) + "#" + s; 
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        int j = 0;
        string len = "";
        while (i < s.size()) { //5#Hello5#World
            if (s[i] != '#') {
                len += s[i];
                ++i;
            }
            else {
                int len_int = std::stoi(len);
                len.clear();
                ++i;
                res.push_back("");
                for (int k = 0; k < len_int; ++k) {
                    res[j] += s[i];
                    ++i;
                }
                ++j;
            }
        }
        return res;
    }
};
