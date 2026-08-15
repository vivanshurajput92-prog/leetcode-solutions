/*
 * Problem: Longest Subsequence With Non-Zero Bitwise XOR
 * Problem ID: 4033
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 171.3 MB
 * Synced From: LeetCode
 * Date: 2026-08-15
 */

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int val = 0;
        bool found = false;
        for(int i=0;i<n;i++){
            if(nums[i] > 0) found = true;
            val = nums[i] ^ val;
        }
        if(!found) return 0;
        if(val != 0) return n;
        else if(val == 0) return n-1;
        return -1;
    }
};