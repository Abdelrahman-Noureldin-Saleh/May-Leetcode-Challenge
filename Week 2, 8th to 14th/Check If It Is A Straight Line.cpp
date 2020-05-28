
const static double EPS = 1e-10;
const static long double INF = numeric_limits<long double>::max();
    
class Solution {
public:
    
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        
        if (n <= 2) return true;
        int y = coordinates[1][1] - coordinates[0][1];
        int x = coordinates[1][0] - coordinates[0][0];
        long double slope = (x == 0 ? INF : (long double) y / x);
        for (int i = 2; i < n; i++){
            int y1 = (coordinates[i][1] - coordinates[0][1]);
            int x1 = (coordinates[i][0] - coordinates[0][0]);
            long double slope1 = (x1 == 0 ? INF : (long double) y1 / x1);
           if (abs(slope1 - slope) > EPS)
                return false;
        }
        return true;
    }
};