/*
 * Problem: Uncrossed Lines
 * Problem ID: 1105
 * Difficulty: Medium
 * Language: C++
 * Runtime: 47 ms
 * Memory: 16.5 MB
 * Synced From: LeetCode
 * Date: 2026-11-11
 */

class Solution {
private:
    int f(int i,int j,vector<int> &nums1,vector<int> &nums2,vector<vector<int>> &dp){
        if(i == nums1.size() || j == nums2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int k=j;k<nums2.size();k++){
            if(nums2[k] == nums1[i]) ans = max(ans,1+f(i+1,k+1,nums1,nums2,dp));
        }
        return dp[i][j] = max(ans,f(i+1,j,nums1,nums2,dp));
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,nums1,nums2,dp);
    }
};