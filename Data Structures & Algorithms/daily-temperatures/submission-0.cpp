class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> ans(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++) {
            if (s.empty() || temperatures[s.top()] >= temperatures[i]) {
                s.push(i);
                continue;
            }
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
