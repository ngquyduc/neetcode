class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int l = 0, r = heights.size() - 1;
        int chl = 0, chr = 0;
        while (l < r) {
            ans = max(ans, min(heights[l], heights[r]) * (r - l));
            chl = max(chl, heights[l]);
            chr = max(chr, heights[r]);
            if (heights[l] <= heights[r]) {
                while (l < r && heights[l] <= chl) {
                    l++;
                }
            } else {
                while (l < r && heights[r] <= chr) {
                    r--;
                }
            }
        }
        return ans;
    }
};
