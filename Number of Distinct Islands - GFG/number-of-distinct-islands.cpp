//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs( int row, int col, vector<vector<int>> &A, vector<vector<int>> &vis,
                vector<pair<int,int>> &temp, int startRow, int startCol ){
        
        int n = A.size();
        int m = A[0].size();
        vis[row][col] = 1;
        temp.push_back({ row-startRow, col-startCol });
        
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        
        for( int i=0;i<4;i++ ){
            int newRow = row + dr[i], newCol = col + dc[i];
            
            if( newRow>=0 && newRow<n && newCol>=0 && newCol<m &&
                vis[newRow][newCol] != 1 && A[newRow][newCol] == 1 ){
               dfs( newRow, newCol, A, vis, temp, startRow, startCol );         
            }
        }
        return;
        
    }
    
    int countDistinctIslands(vector<vector<int>>& A) {
        
        int n = A.size();
        int m = A[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        
        for( int i=0;i<n;i++ ){
            for( int j=0;j<m;j++ ){
                if( (A[i][j] == 1) && (vis[i][j] != 1) ) {
                    vector<pair<int,int>> temp;
                    dfs(i, j, A, vis, temp, i, j );
                    st.insert(temp);
                }
            }
        }
        
        return st.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends