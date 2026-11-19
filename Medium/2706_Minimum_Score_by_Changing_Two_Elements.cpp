/*
 * Problem: Minimum Score by Changing Two Elements
 * Problem ID: 2706
 * Difficulty: Medium
 * Language: C++
 * Runtime: 14 ms
 * Memory: 38 MB
 * Synced From: LeetCode
 * Date: 2026-11-19
 */

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min({nums[n-1] - nums[2], nums[n-3] - nums[0], nums[n-2] - nums[1]});
    }
};