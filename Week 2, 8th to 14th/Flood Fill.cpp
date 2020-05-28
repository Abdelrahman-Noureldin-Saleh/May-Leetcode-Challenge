class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        fill(image, sr, sc, n, m, image[sr][sc]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (image[i][j] == -1)
                    image[i][j] = newColor;
        return image;
        
    }
    
    void fill(vector<vector<int>>& image, int i, int j, int n, int m, int color){
        if (i >= n || i < 0 || j >= m || j < 0 || image[i][j] == -1 || image[i][j] != color)
            return;
        
        image[i][j] = -1;
        fill(image, i+1, j, n, m, color);
        fill(image, i-1, j, n, m, color);
        fill(image, i, j+1, n, m, color);
        fill(image, i, j-1, n, m, color);
    }
};