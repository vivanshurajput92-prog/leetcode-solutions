/*
 * Problem: Maximum K to Sort a Permutation
 * Problem ID: 3950
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 152.3 MB
 * Synced From: LeetCode
 * Date: 2026-10-23
 */

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i] != i) ans = min(ans,nums[i] & ans);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};