class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 0;
        int high = sqrt(INT_MAX);
        while (low <= high){
            int mid = (high + low) / 2;
            if (mid * mid > num)
                high = mid - 1 ;
            else if (mid * mid < num)
                low = mid + 1;
            else
                return true;
        }
        return false;
    }
};