/*
 * Problem: Minimum Moves to Equal Array Elements II
 * Problem ID: 462
 * Difficulty: Medium
 * Language: C++
 * Runtime: 1 ms
 * Memory: 15.5 MB
 * Synced From: LeetCode
 * Date: 2026-11-02
 */

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n  = nums.size();
        sort(nums.begin(),nums.end());
        int median = nums[n/2];
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += abs(median - nums[i]);
        }
        return ans;
    }
};