class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        if( k == nums.size() ) return nums;
        vector<int> Ans;
        unordered_map<int,int> mp;
        priority_queue<int,vector<int>, greater<int>> minQueue;
        int n = nums.size();
        for( int i=0;i<n;i++ ){
            minQueue.push(nums[i]);
            if( minQueue.size() > k ) minQueue.pop();
        }
        while( !minQueue.empty() ){
            mp[minQueue.top()]++;
            minQueue.pop();
        }
        for( int i=0;i<n;i++ ){
            if( mp[nums[i]] >= 1 ){
                Ans.push_back(nums[i]);
                mp[nums[i]]--;
            }
        }
        return Ans;
    }
};