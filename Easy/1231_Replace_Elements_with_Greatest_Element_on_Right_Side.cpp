/*
 * Problem: Replace Elements with Greatest Element on Right Side
 * Problem ID: 1231
 * Difficulty: Easy
 * Language: C++
 * Runtime: 3 ms
 * Memory: 72.7 MB
 * Synced From: LeetCode
 * Date: 2026-08-04
 */

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,-1);
        int maxi = arr[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i] = maxi;
            maxi = max(maxi,arr[i]);
        }
        return ans;
    }
};