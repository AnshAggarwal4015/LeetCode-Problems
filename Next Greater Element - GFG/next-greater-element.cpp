//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> A, int n){
        stack<long long> s;
        vector<long long> Ans(n);
        long long index = n-2;
        s.push(A[n-1]);
        Ans[n-1] = -1;
        
        for( long long i=n-2;i>=0;i-- ){
                while( !s.empty() && s.top() <= A[i] ){
                    s.pop();
                }
                if( s.empty() ) {
                    Ans[i] = -1;
                } else {
                    Ans[i] = s.top();
                }
            // }
            s.push(A[i]);
        }
        return Ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends