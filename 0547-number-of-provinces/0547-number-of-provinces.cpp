class Solution {
public:
    int n;
    
    
    void dfs( vector<vector<int>> & adjList, int node, vector<bool> &visited ){
        visited[node] = true;
        for( auto it : adjList[node] ){
            if( visited[it] == false ){
                dfs(adjList, it, visited );
            }
        }
        return ;
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<vector<int>> adjList(n);
        
        // We Have Created our Adjacency List Here
        for( int i=0;i<n;i++ ){
            for( int j=0;j<n;j++ ){
                
                if( isConnected[i][j] == 1 && (i != j) ){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        // To find the number of unconnected components we have to traverse through all the nodes
        int ans = 0;
        for( int i=0;i<n;i++ ){
            if( visited[i] == false ){
                cout<<i<<endl;
                cout<<"Value of ans is : "<<ans<<endl;
                dfs( adjList, i, visited );
                ans++;
            }
        }
        
        return ans;
        
    }
};