class Solution {
public:
    
    void solve( int row, int col, vector<vector<int>>&image, vector<vector<int>>&Ans, int initialColor, int newColor,
               vector<int> &dR, vector<int> &dC ){
        
        int n = image.size();
        int m = image[0].size();
        Ans[row][col] = newColor;
        for( int i=0;i<4;i++ ){
            int newRow = row + dR[i];
            int newCol = col + dC[i];
            
            if( newRow >=0 && newRow < n && newCol >=0 && newCol < m &&
              image[newRow][newCol] == initialColor && Ans[newRow][newCol] != newColor ) {
                solve( newRow, newCol, image, Ans, initialColor, newColor, dR, dC );    
            }
        }
        
        return;
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> Ans = image;
        int n = image.size(), m = image[0].size();
        int initialColor = image[sr][sc];
        vector<int> dR = {-1, 0, 1, 0};
        vector<int> dC = {0, +1, 0,-1};
        
        solve(sr, sc, image, Ans, initialColor, color, dR, dC );
        return Ans;
    }
};