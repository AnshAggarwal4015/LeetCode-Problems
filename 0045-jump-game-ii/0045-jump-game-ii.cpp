class Solution {
public:
    int jump(vector<int>& A) {
        int n = A.size();
        vector<int> Ans(n,0);
        
        for( int i=(n-2);i>=0;i-- ){
            if( A[i] == 0 ) Ans[i] = INT_MAX;
            else {
                int steps = INT_MAX;
                for( int j=1;j<=A[i]&&((i+j)<n);j++ ){
                    steps = min( steps, Ans[i+j] );
                }
                if( steps == INT_MAX ){
                    Ans[i] = INT_MAX;
                } else {
                    Ans[i] = steps + 1;                
                }
                cout<<"Value of i and steps is : "<<i<<"   "<<steps<<endl;
            }
        }
        
        for( auto i : Ans ){
            cout<<i<<" ";
        }
        
        return Ans[0];
    }
};