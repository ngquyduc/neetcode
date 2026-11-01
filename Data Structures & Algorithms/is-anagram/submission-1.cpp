class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hm;
        for (char &cs : s) {
            hm[cs]++;
        }
        for (char &ct : t) {
            if (--hm[ct] == -1) {
                return false;
            }
        }
        return s.size() == t.size();
    }
};
