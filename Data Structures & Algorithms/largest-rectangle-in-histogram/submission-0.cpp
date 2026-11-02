class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s1, s2;
        vector<int> v1(heights.size()), v2(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            while (!s1.empty() && heights[s1.top()] > heights[i]) {
                int j = s1.top();
                s1.pop();
                v1[j] = i;
            }
            s1.push(i);
        }
        while (!s1.empty()) {
            int j = s1.top();
            s1.pop();
            v1[j] = heights.size();
        }
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!s2.empty() && heights[s2.top()] > heights[i]) {
                int j = s2.top();
                s2.pop();
                v2[j] = i;
            }
            s2.push(i);
        }
        while (!s2.empty()) {
            int j = s2.top();
            s2.pop();
            v2[j] = -1;
        }
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            ans = max(ans, heights[i] * (v1[i] - v2[i] - 1));
        }
        return ans;
    }
};
