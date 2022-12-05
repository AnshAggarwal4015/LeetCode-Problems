class Solution {
public:
    //Important Question
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        //{{row, col}, time }
        queue<pair<pair<int,int>, int>> q;
        int countFresh = 0;
        int vis[n][m];
        for( int i=0;i<n;i++ ){
            for( int j=0;j<m;j++ ){
                if( grid[i][j] == 2 ){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
                if( grid[i][j] == 1 ) countFresh++;
            }
        }
        
        int dR[] = {-1, 0, 1, 0};
        int dC[] = {0 ,1, 0, -1};
        int count = 0;
        int ans = 0;
        while( !q.empty() ){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            ans = max( ans, time );
            
            for( int i=0;i<4;i++ ){
                int newRow = row + dR[i];
                int newCol = col + dC[i];
                
                if( newRow >=0 && newRow < n && newCol >= 0 && newCol < m &&
                   grid[newRow][newCol] == 1 && vis[newRow][newCol] == 0 ){
                    q.push({{newRow, newCol}, time + 1});
                    vis[newRow][newCol] = 2;
                    count++;
                }
            }
        }
        if( count == countFresh ) return ans;
        else return -1;
        
    }
};