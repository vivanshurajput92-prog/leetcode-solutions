/*
 * Problem: Stone Game
 * Problem ID: 909
 * Difficulty: Medium
 * Language: C++
 * Runtime: 23 ms
 * Memory: 19.8 MB
 * Synced From: LeetCode
 * Date: 2026-08-02
 */

class Solution {
private:
    int f(int i,int j,vector<int> &nums,auto &dp){
        if(i == j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        int pickRight = nums[j] - f(i,j-1,nums,dp);
        int pickLeft = nums[i] - f(i+1,j,nums,dp);
        return dp[i][j] = max(pickLeft,pickRight);
    }
public:
    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,n-1,nums,dp);
    }
};