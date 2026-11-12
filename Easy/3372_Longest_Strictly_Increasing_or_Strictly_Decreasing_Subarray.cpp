/*
 * Problem: Longest Strictly Increasing or Strictly Decreasing Subarray
 * Problem ID: 3372
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 27.6 MB
 * Synced From: LeetCode
 * Date: 2026-11-12
 */

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int ct = 1;
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]) ct++;
            else{
                ans = max(ans,ct);
                ct = 1;
            }
        }
        ans = max(ans,ct);
        ct = 1;
        for(int i=1;i<n;i++){
            if(nums[i] < nums[i-1]) ct++;
            else{
                ans = max(ans,ct);
                ct = 1;
            }
        }
        ans = max(ans,ct);
        return ans;
    }
};