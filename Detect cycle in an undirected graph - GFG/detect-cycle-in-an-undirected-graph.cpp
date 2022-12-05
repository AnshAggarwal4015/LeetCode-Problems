//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis( V+1, 0 );
        for( int i=0;i<V;i++ ){
            if( !vis[i] ){
                int prev = -1;
                queue<pair<int,int>> q;
                q.push({i,prev});
                vis[i] = 1;
                while( !q.empty() ){
                    
                    int node = q.front().first;
                    int parent = q.front().second;
                    prev = node;
                    q.pop();
                    for( auto it : adj[node] ){
                        if( !vis[it] ){
                            q.push( { it, prev } );
                            vis[it] = 1;
                        } else if( vis[it] == 1 && parent != it ){
                            return true;
                        }
                    }
                }
                
            }
        }
        return false;
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends