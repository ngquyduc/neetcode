class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            ++freq[n];
        }
        
        vector<vector<int>> b(nums.size() + 1);
        for (auto& [n, cnt] : freq) {
            b[cnt].push_back(n);
        }

        vector<int>ans;
        for (int c = nums.size(); c >= 1 && ans.size() < k; c--) {
            for (int n: b[c]) {
                ans.push_back(n);
                if (ans.size() == k) break;
            }
        }
        return ans;
    }
};

// O(n)
// use buckets [count : num]
// pick from high to low until we get k most frequent elements and we stop
