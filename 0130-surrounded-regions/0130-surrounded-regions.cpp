class Solution {
public:
    
    void dfs( vector<vector<char>> &A, vector<vector<int>> &vis, int row, int col ){
        vis[row][col] = 1;
        
        int n = A.size();
        int m = A[0].size();
        
        int dr[] = { 0, -1, 0, 1 };
        int dc[] = { -1, 0, 1, 0 };
        
        for( int i=0;i<4;i++ ){
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            
            if( newRow>=0 && newRow<n && newCol>=0 && newCol<m && vis[newRow][newCol] != 1 && A[newRow][newCol] == 'O' ){
                dfs(A, vis, newRow, newCol );
            }
        }
        
        return;
    }
    
    void solve(vector<vector<char>>& A) {
        
        int n = A.size();
        int m = A[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0) );
        
        for( int i=0;i<n;i++ ){
            
            if(!vis[i][0] && A[i][0] == 'O') {
                dfs(A, vis, i, 0); 
            }
            
            if(!vis[i][m-1] && A[i][m-1] == 'O') {
                dfs(A, vis, i, m-1); 
            }
        }
        
        for( int i=0;i<m;i++ ){
            if(!vis[0][i] && A[0][i] == 'O') {
                dfs(A, vis, 0, i); 
            }
            
            if(!vis[n-1][i] && A[n-1][i] == 'O') {
                dfs(A, vis, n-1, i); 
            }
        }
        
        for( int i=0;i<n;i++ ){
            for( int j=0;j<m;j++ ){
                if( A[i][j] == 'O' && vis[i][j] != 1 ) A[i][j] = 'X';
            }
        }
        return;
    }
};