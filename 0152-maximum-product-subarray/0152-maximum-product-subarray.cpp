class Solution {
public:
    int maxProduct(vector<int>& A) {
        int maxEnding = A[0], minEnding = A[0], ans = A[0];
        
        for( int i=1;i<A.size();i++ ){
            int temp = max( A[i], max(A[i]*minEnding, A[i]*maxEnding ) );
            minEnding = min( A[i], min(A[i]*minEnding, A[i]*maxEnding) );
            maxEnding = temp;
            ans = max( ans, maxEnding );
        }
        return ans;
        
    }
};