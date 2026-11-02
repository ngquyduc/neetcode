class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char p : s) {
            if (p == '(' || p == '{' || p == '[') {
                st.push(p);
            } else {
                if (st.empty()) {
                    return false;
                }
                char t = st.top();
                st.pop();
                if ((p == ')' && t != '(') || (p == '}' && t != '{') || (p == ']' && t != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};  
