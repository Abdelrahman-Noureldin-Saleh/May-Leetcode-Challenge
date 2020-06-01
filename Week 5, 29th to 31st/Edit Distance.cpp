class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> table(n+1, vector<int>(m+1, 0));
        for (int i = 0; i <= n; i++) table[i][0] = i;
        for (int j = 0; j <= m; j++) table[0][j] = j;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                table[i][j] =   min(table[i-1][j] + 1,
                                min(table[i][j-1] + 1, 
                                    table[i-1][j-1] + (word1[i-1] != word2[j-1])));
        return table[n][m];
    }
};