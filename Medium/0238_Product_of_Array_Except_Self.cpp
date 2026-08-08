/*
 * Problem: Product of Array Except Self
 * Problem ID: 238
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 42.2 MB
 * Synced From: LeetCode
 * Date: 2026-08-08
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,nums[0]);
        vector<int> suffix(n,nums[n-1]);
        for(int i=1;i<n;i++) prefix[i] = prefix[i-1] * nums[i];
        for(int i=n-2;i>=0;i--) suffix[i] = suffix[i+1] * nums[i];
        vector<int> ans(n);
        ans[0] = suffix[1];
        for(int i=1;i<n-1;i++){
            ans[i] = suffix[i+1] * prefix[i-1];
        }
        ans[n-1] = prefix[n-2];
        return ans;
    }
};