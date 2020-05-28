class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ans;
        for (int i = 0; i < nums.size(); i++){
            if (!count) ans = nums[i];
            count += nums[i] == ans ? 1 : -1;
        }
        return ans;
    }
};