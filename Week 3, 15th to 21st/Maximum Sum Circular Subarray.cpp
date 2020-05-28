class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        int cur = A[0];
        int sum = A[0];
        int mx = A[0];
        int tot = A[0];
        int mn = A[0];
        
       for (int i = 1; i < n; i++){
            tot += A[i];
            cur = max(cur + A[i], A[i]);
            mx = max(mx, cur);
            sum = min(sum + A[i], A[i]);
            mn = min(mn, sum);
            
       }
        
        
        return tot-mn ? max(mx, tot-mn) : mx;
        
        
        
    }
};