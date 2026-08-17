/*
 * Problem: Jump Game
 * Problem ID: 55
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 52.3 MB
 * Synced From: LeetCode
 * Date: 2026-08-17
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for(int i=0;i<nums.size();i++){
            if(reach < i) return false;
            reach = max(reach,nums[i]+i);
        }
        return true;
    }
};