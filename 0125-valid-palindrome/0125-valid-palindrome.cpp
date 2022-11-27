class Solution {
public:
    bool isPalindrome(string s) {
        string A;
        for( int i=0;i<s.length();i++ ){
            if( ( int(s[i]) >= 97 && int(s[i]) <= 122 ) || ( int(s[i]) >= 65 && int(s[i]) <= 90 ) || ( int(s[i]) >= 48 && int(s[i]) <= 57 ) ){
                s[i] = tolower(s[i]);
                A += s[i];
            }
        }
        int n = A.length();
        if( n == 0 || n == 1 ){
            return true;
        } 
        for( int i=0;i<=(n-1)/2;i++ ){
            if( A[i] != A[n-i-1] ){
                return false;
            }
        }
        return true;
    }
};