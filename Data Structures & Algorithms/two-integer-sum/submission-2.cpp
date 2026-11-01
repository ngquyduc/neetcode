class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hs;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hs.find(nums[i]);
            if (it == hs.end()) {
                int diff = target - nums[i];
                hs[diff] = i;
                continue;
            }
            return {it->second, i};
        }
    }
};
