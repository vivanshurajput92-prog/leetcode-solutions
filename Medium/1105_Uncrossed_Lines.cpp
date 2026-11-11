/*
 * Problem: Uncrossed Lines
 * Problem ID: 1105
 * Difficulty: Medium
 * Language: C++
 * Runtime: 81 ms
 * Memory: 16.5 MB
 * Synced From: LeetCode
 * Date: 2026-11-11
 */

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans = 0;
                for(int k=j;k<m;k++){
                    if(nums1[i] == nums2[k]) ans = max(ans,1+dp[i+1][k+1]);
                }
                ans = max(ans,dp[i+1][j]);
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};