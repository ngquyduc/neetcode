class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (int n: nums) {
            if (s.contains(n - 1)) {
                continue;
            }
            int i = n;
            while (s.contains(i)) {
                i++;
            }
            ans = max(ans, i - n);
        }
        return ans;
    }
};
