class Solution {
    private:
    bool solve( vector<vector<int>> &A, vector<int> &color, int node ){
        
        queue<int> q;
        q.push(node);
        
        while( !q.empty() ){
            int top = q.front();
            q.pop();
            
            for( auto it : A[top] ){
                if( color[it] == -1 ){
                    color[it] = !color[top];
                    q.push(it);
                } else if( color[it] == color[top] ) return false;
            }
        }
        return true;
        
    }
    
    public:
    bool isBipartite(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> color( n, -1 );
        for( int i=0;i<n;i++ ){
            if( color[i] == -1 ){
                color[i] = 1;
                bool flag = solve(A, color, i);
                if( flag == false ) return false;
            }
        }
        return true;
    }
};