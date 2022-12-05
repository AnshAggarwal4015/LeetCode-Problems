class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        int dx[] = {-1, 0, +1, 0};
        int dy[] = {0, +1, 0, -1};
        
        //{{row,col}, distance}
        queue< pair<pair<int,int>,int> > q;
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> ans(n, vector<int>(m,0));
        
        for( int i=0;i<n;i++ ){
            for( int j=0;j<m;j++ ){
                if( A[i][j] == 0 ){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        
        while( !q.empty() ){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;
            ans[x][y] = dis;
            q.pop();
            for( int i=0;i<4;i++ ){
                int newRow = x+dx[i];
                int newCol = y+dy[i];
                if( newRow >= 0 && newRow<n && newCol>=0 && newCol<m && vis[newRow][newCol] != 1 ){
                    vis[newRow][newCol] = 1;
                    q.push( {{newRow, newCol},dis+1} );
                }
            }
        }
        
        return ans;
        
        
    }
};