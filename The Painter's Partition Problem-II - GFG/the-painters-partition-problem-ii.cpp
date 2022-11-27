//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
    bool solve( int A[], int n, int k, long long mid ){
        
        long long sum = 0;
        long long painter = 1;
        for( long long i=0;i<n;i++ ){
            if( sum+A[i] > mid ){
                painter++;
                sum = 0;
            }
            if( painter > k ) return false;
            sum += A[i];
        }
        // cout<<"No. of Painters are : "<<painter<<endl;
        if( painter > k ){
            return false;
        }
        return true;
        
    }
  
    long long minTime(int arr[], int n, int k)
    {
        int low = INT_MIN;
        long long high = 0;
        for( long long i=0;i<n;i++ ){
            low = max( low, arr[i] );
            high += arr[i];
        }
        long long ans = high;
        while( low <= high ){
            long long mid = low + (high - low)/2;
            // cout<<"Mid value is : "<<mid<<endl;
            
            bool flag = solve( arr, n, k, mid );
            
            if( flag == false ){
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends