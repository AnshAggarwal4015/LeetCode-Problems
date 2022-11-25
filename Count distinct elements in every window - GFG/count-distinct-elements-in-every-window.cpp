//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        unordered_map<int,int> mp;
        vector<int> Ans;
        int distinct = 0;
        for( int i=0;i<k;i++ ){
            if( mp.find(A[i]) == mp.end() ){
                distinct++;
            }
               mp[A[i]]++;
        }
        int index = 0;
        Ans.push_back(distinct);
        int prevElement = A[index++];
        for( int i=k;i<n;i++ ){
            mp[prevElement]--;
            if( mp[prevElement] == 0 ) {
                mp.erase(prevElement);
                distinct--;
            }
            if( mp.find(A[i]) == mp.end() ){
                distinct++;
            }            
            mp[A[i]]++;
            Ans.push_back(distinct);
            prevElement = A[index++];
        }

        return Ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends