class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        int n = A.size();
        priority_queue<int, vector<int> , greater<int> > pq;
        for( int i=0;i<n;i++ ){
            pq.push(A[i]);
            if( pq.size() > k ) pq.pop();
        }
        return pq.top();
    }
};