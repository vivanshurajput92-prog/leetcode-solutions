/*
 * Problem: Combination Sum II
 * Problem ID: 40
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 14.3 MB
 * Synced From: LeetCode
 * Date: 2026-08-04
 */

class Solution {
    vector<vector<int>> ans;
private:
    void f(int i,vector<int> &nums,vector<int> &used,int target,int n){
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
        for (int j = i; j < n; j++) {
            if (j > i && nums[j] == nums[j - 1]) continue;
            if (nums[j] > target) break;
            used.push_back(nums[j]);
            f(j + 1, nums, used, target - nums[j], n);
            used.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> used;
        f(0,nums,used,target,n);
        return ans;
    }
};