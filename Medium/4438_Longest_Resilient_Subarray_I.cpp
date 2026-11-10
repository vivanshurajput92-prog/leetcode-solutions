/*
 * Problem: Longest Resilient Subarray I
 * Problem ID: 4438
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 39.4 MB
 * Synced From: LeetCode
 * Date: 2026-11-10
 */

class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int ans = 1;
        int len = 1;

        for (int i = 1; i < nums.size(); i++) {
            int r = nums[i] % k;
            if (r == nums[i-1]%k) {
                len++;
            } else {
                len = 1;
            }
            if ((len - 1) * r % k == 0) {
                ans = max(ans, len);
            }
        }
        return ans;
    }
};