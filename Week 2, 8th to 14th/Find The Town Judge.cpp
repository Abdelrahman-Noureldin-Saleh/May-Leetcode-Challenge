class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
    
        vector<int> trustedBy(N+1, 0);
        for (int i = 0; i < trust.size(); i++)
            trustedBy[trust[i][0]]--, trustedBy[trust[i][1]]++;
        
        for (int i = 1; i < trustedBy.size(); i++)
            if (trustedBy[i] == N-1)
                return i;
        return -1;
    }
};

static int x = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();