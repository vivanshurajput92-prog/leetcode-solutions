/*
 * Problem: Find the Maximum Length of Valid Subsequence I
 * Problem ID: 3490
 * Difficulty: Medium
 * Language: C++
 * Runtime: 338 ms
 * Memory: 210.9 MB
 * Synced From: LeetCode
 * Date: 2026-10-13
 */

class Solution {
private:
    int f(int i,vector<int> &nums,int last_parity,vector<vector<int>> &dp){
        int n = nums.size();
        if(i == n) return 0;
        if(dp[i][last_parity+1] != -1) return dp[i][last_parity+1];
        int pick = 0;
        if(last_parity == -1 || last_parity != nums[i] % 2) pick = 1 + f(i+1,nums,nums[i]%2,dp);
        int notPick = f(i+1,nums,last_parity,dp);
        return dp[i][last_parity+1] = max(pick,notPick);
    }
    int g(int i,vector<int> &nums,int last_parity,vector<vector<int>> &dp){
        int n = nums.size();
        if(i == n) return 0;
        if(dp[i][last_parity+1] != -1) return dp[i][last_parity+1];
        int pick = 0;
        if(last_parity == -1 || last_parity == nums[i] % 2) pick = 1 + g(i+1,nums,nums[i]%2,dp);
        int notPick = g(i+1,nums,last_parity,dp);
        return dp[i][last_parity+1] = max(pick,notPick);
    }
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp1(n,vector<int>(3,-1)),dp2(n,vector<int>(3,-1));
        return max(g(0,nums,-1,dp1),f(0,nums,-1,dp2));
    }
};