class Solution {
public:
    int numSquares(int n) {
        
        int dp[n+1];
	    for( int i=0;i<=n;i++ ){
	        dp[i] = i;
	    }
	    dp[0] = 0;
	    dp[1] = 1;
	    
	    for( int i=2;i<=n;i++ ){
	        int help = sqrt(i);
	        for( int j=help;j>=1;j-- ){
	            int diff = i - j*j;
	            if( diff == 0 ){
	                dp[i] = 1;
	            }
	            dp[i] = min( dp[i], 1 + dp[diff] );
	        }
	    }
	    return dp[n];
        
        
    }
};