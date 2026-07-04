class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<string>> grouped;
        std::unordered_map<string, std::vector<string>> mp;
        for (int i = 0; i < strs.size(); ++i) {
            std::string tmp = strs[i];
            std::sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(strs[i]);
        }

        for (auto& pairs : mp) {
            grouped.push_back(pairs.second);
        }
        return grouped;
    }
};
