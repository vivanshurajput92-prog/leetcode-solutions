/*
 * Problem: Two Sum II - Input Array Is Sorted
 * Problem ID: 167
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 25.4 MB
 * Synced From: LeetCode
 * Date: 2026-10-20
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0,j = n-1;
        while(i < j){
            if(nums[i] + nums[j] == target) return {i+1,j+1};
            else if(nums[i] + nums[j] > target) j--;
            else i++;
        }
        return {};
    }
};