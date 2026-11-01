class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (string s: strs) {
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        size_t i = 0;
        while (i < s.size()) {
            size_t p = s.find("#", i);
            size_t l = static_cast<size_t>(stoull(s.substr(i, p - i)));
            string ss = s.substr(p + 1, l);
            decoded.push_back(ss);
            i += p - i + 1 + l;
        }
        return decoded;
    }
};

// time complexity: O(n * l)
// n is the size of strs
// l is the length of a string