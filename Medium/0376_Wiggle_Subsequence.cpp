/*
 * Problem: Wiggle Subsequence
 * Problem ID: 376
 * Difficulty: Medium
 * Language: C++
 * Runtime: 320 ms
 * Memory: 100.2 MB
 * Synced From: LeetCode
 * Date: 2026-08-07
 */

class Solution {
private:
    int f(int i,vector<int> &nums,int j,int last,vector<vector<vector<int>>> &dp){
        if(i >= nums.size()) return 0;
        if(dp[i][j+1][last+2] != -1) return dp[i][j+1][last+2];
        int pick = INT_MIN;
        if(j == -1) pick = 1 + f(i+1,nums,i,-1,dp);
        else if(last == -1 && nums[i] != nums[j]) pick = 1 + f(i+1,nums,i,nums[i] - nums[j] > 0 ? 1 : 0,dp);
        else if(last == 0 && nums[i] > nums[j]) pick = 1 + f(i+1,nums,i,1,dp);
        else if(last == 1 && nums[i] < nums[j]) pick = 1 + f(i+1,nums,i,0,dp);
        int notPick = f(i+1,nums,j,last,dp);
        return dp[i][j+1][last+2] = max(pick,notPick);
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n+1,vector<int>(4,-1)));
        return f(0,nums,-1,-2,dp);
    }
};