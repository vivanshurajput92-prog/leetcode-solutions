/*
 * Problem: Combination Sum IV
 * Problem ID: 377
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 9.2 MB
 * Synced From: LeetCode
 * Date: 2026-08-07
 */

class Solution {
private:
    int f(vector<int> &nums,int target,int n,vector<int> &dp){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(dp[target] != -1) return dp[target];
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += f(nums,target-nums[i],n,dp);
        }
        return dp[target] = ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1,-1);
        return f(nums,target,n,dp);
    }
};