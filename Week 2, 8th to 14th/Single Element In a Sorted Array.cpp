class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        while (low <= high){
            mid = (low + high)/2;
            if (mid > 0 && nums[mid] == nums[mid-1])
                if (mid % 2)
                    low = mid + 1;
                else
                    high = mid - 2;
            else if (mid < nums.size()-1 && nums[mid] == nums[mid+1])
                if (mid % 2)
                    high = mid - 1;
                else 
                    low = mid + 2;
            else 
                return nums[mid];
        }
        return nums[mid];
    }
};