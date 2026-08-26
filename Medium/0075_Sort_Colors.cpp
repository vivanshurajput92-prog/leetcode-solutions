/*
 * Problem: Sort Colors
 * Problem ID: 75
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 11.5 MB
 * Synced From: LeetCode
 * Date: 2026-08-26
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j < n-1 && nums[j] == 2) swap(nums[j],nums[j+1]);
                else if(j > 0 && nums[j] == 0) swap(nums[j-1],nums[j]);
            }
        }
    }
};