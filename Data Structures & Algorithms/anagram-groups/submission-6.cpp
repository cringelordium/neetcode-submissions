class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<string>> grouped;
        std::unordered_map<string, std::vector<int>> mp;
        std::vector<string> sk;
        for (int i = 0; i < strs.size(); ++i) {
            std::string tmp = strs[i];
            std::sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(i);
        }

        for (auto& pairs : mp) {
            for (int i = 0; i < pairs.second.size(); ++i) {
                sk.push_back(strs[pairs.second[i]]);
            }
            grouped.push_back(sk);
            sk.clear();
        }
        return grouped;
    }
};
