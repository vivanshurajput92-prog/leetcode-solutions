/*
 * Problem: Combination Sum
 * Problem ID: 39
 * Difficulty: Medium
 * Language: C++
 * Runtime: 95 ms
 * Memory: 72.4 MB
 * Synced From: LeetCode
 * Date: 2026-08-04
 */

class Solution {
    vector<vector<int>> ans;
    void f(int i,vector<int> &nums,vector<int> used,int target){
        int n = nums.size();
        if(target == 0){
            ans.push_back(used); 
            return;
        }
        else if(target < 0) return;
        else if(i == n && target == 0){
            ans.push_back(used);
            return;
        }
        else if(i == n) return;
        f(i+1,nums,used,target);
        used.push_back(nums[i]);
        f(i,nums,used,target-nums[i]);
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> used;
        f(0,nums,used,target);
        return ans;
    }
};