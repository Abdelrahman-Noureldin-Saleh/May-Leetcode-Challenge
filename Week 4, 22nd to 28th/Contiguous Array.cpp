class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(); if (n == 0) return 0;
        unordered_map<int, int> m;
        int sum = 0;
        int ans = 0;
        m[0] = -1;
        for (int i = 0; i < n; i++){
            sum += nums[i] == 0 ? -1 : 1;
            if (m.count(sum)) ans = max(ans, i - m[sum]);
            else m[sum] = i;
        }
        return ans;
    }
};

auto fast = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();