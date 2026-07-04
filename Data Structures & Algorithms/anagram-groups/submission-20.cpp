class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<string>> grouped;
        std::unordered_map<std::string, std::vector<string>> mp;
        for (auto& s : strs) {
            std::array<int, 26> counter{0};
            for (auto& c : s) {
                counter[c - 'a']++;
            }
            string key;
            key.reserve(100);
            for (int l = 0; l < 26; ++l) {
                key += "#" + to_string(counter[l]);
            }
            mp[key].push_back(s);
        }

        for (auto& pairs : mp) {
            grouped.push_back(pairs.second);
        }
        return grouped;
    }
};
