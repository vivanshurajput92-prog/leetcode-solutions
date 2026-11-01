/*
 * Problem: Minimum Moves to Equal Array Elements
 * Problem ID: 453
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 32 MB
 * Synced From: LeetCode
 * Date: 2026-11-01
 */

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX;
        for(int i=0;i<n;i++){
            mn = min(mn,nums[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += abs(mn - nums[i]);
        }
        return ans;
    }
};