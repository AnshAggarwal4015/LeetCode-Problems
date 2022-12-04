class Solution {
public:
    void solve( int i, int j, int n, int m, vector<vector<char>> &A ){
        if( i<0 || i>=n || j<0 || j>=m || A[i][j] != '1' ) return;
        
        A[i][j] = '2';
        
        solve( i, j-1, n, m, A);
        solve( i, j+1, n, m, A);
        solve( i+1, j, n, m, A);
        solve( i-1, j, n, m, A);
        return;
    }
    
    int numIslands(vector<vector<char>>& A) {
        int n = A.size();
        int m = A[0].size();    
        
        if( n == 0 ) return 0;
        
        int ans = 0;
        for( int i=0;i<n;i++ ){
            for( int j=0;j<m;j++ ){
                if( A[i][j] == '1' ){
                    ans += 1;
                    solve( i, j, n, m, A );    
                }
            }
        }
        
        return ans;
    }
};