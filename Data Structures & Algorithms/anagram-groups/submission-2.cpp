class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> groups;
        
        for (string &s : strs) {
            vector<int> c(26, 0);
            for (char &c_s : s) {
                c[c_s - 'a']++;
            }
            string key;
            for (int freq : c) {
                key += to_string(freq) + ",";
            }
            groups[key].push_back(s);
        }
        
        for (auto& [key, words] : groups) {
            ans.push_back(words);
        }

        return ans;
    }
};
