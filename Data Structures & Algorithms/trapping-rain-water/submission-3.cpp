class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int l = 0;
        while (l < height.size()) {
            int r = l + 1;
            while (r < height.size() && height[l] > height[r]) {
                r++;
            }
            if (r == height.size()) break;
            int taken = accumulate(height.begin() + l + 1, height.begin() + r, 0);
            ans += min(height[l], height[r]) * (r - l - 1) - taken;
            l = r;
        }
        int r = height.size() - 1;
        while (r > 0) {
            int l = r - 1;
            while (l >= 0 && height[r] >= height[l]) {
                l--;
            }
            if (l == -1) break;
            int taken = accumulate(height.begin() + l + 1, height.begin() + r, 0);
            ans += min(height[l], height[r]) * (r - l - 1) - taken;
            r = l;
        }
        return ans;
    }
};
