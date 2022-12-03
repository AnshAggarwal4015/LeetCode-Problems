class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> lft(n, -1);
        int curr = 0;
        map<int, int> mp;
        mp[0] = -1;
        int mn_till = n + 5, ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            curr += arr[i];
            if(mp.find(curr - target) != mp.end()) {
                int ind = mp[curr - target];
                int temp_len = i - ind;
                mn_till = min(mn_till, temp_len);
                if(ind > -1 && lft[ind] < n) {
                    ans = min(ans, temp_len + lft[ind]);
                }
            }
            lft[i] = mn_till;
            mp[curr] = i;
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};