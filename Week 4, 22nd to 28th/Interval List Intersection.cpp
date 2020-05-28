class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()){
            if (A[i][1] < B[j][0]){ i++; continue; }
            if (B[j][1] < A[i][0]){ j++; continue; }
            int a = max(A[i][0], B[j][0]);
            int b = min(A[i][1], B[j][1]);
            if (a <= b) ans.push_back(vector<int>({a, b}));
            if (A[i][1] < B[j][1]) i++;
            else if (B[j][1] < A[i][1]) j++;
            else i++, j++;
        }
        return ans; 
        
    }
};