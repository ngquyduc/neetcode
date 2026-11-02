class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int ans = 0;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                ans = a + b;
                s.push(ans);
            } else if (tokens[i] == "-") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                ans = a - b;
                s.push(ans);
            } else if (tokens[i] == "*") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                ans = a * b;
                s.push(ans);
            } else if (tokens[i] == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                ans = a / b;
                s.push(ans);
            } else {
                int n = stoi(tokens[i]);
                ans = n;
                s.push(n);
            }
        }
        return ans;
    }
};
