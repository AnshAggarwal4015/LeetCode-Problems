class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n, 1);
        dp[0] = 1;
        int len = 1;
        for( int i=1;i<n;i++ ){
            for( int j=0;j<i;j++ ){
                if( A[i] > A[j] ){
                    dp[i] = max( dp[i], 1 + dp[j] );
                    len = max( len, dp[i] );
                }
            }
        }
        return len;
    }
};