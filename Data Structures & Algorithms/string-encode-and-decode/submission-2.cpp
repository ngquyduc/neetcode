class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (string s: strs) {
            encoded += to_string(s.size()) + "#" + s;
        }
        cout << encoded << "\n";
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        size_t i = 0;
        size_t p = s.find("#");
        while (p != string::npos) {
            size_t l = static_cast<size_t>(stoull(s.substr(i, p - i)));
            string ss = s.substr(p + 1, l);
            
            decoded.push_back(ss);
            cout << l << " | " << ss << ", ";

            s = s.erase(i, p - i + 1 + l);
            p = s.find("#");
        }
        return decoded;
    }
};
