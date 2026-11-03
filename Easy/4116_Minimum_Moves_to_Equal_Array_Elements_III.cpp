/*
 * Problem: Minimum Moves to Equal Array Elements III
 * Problem ID: 4116
 * Difficulty: Easy
 * Language: C++
 * Runtime: 2 ms
 * Memory: 31.3 MB
 * Synced From: LeetCode
 * Date: 2026-11-03
 */

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += (mx - nums[i]);
        }
        return ans;
    }
};