/*
 * Problem: Uncrossed Lines
 * Problem ID: 1105
 * Difficulty: Medium
 * Language: C++
 * Runtime: 78 ms
 * Memory: 12.9 MB
 * Synced From: LeetCode
 * Date: 2026-11-11
 */

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> dp(m+1,0),curr(m+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans = 0;
                for(int k=j;k<m;k++){
                    if(nums1[i] == nums2[k]) ans = max(ans,1+dp[k+1]);
                }
                ans = max(ans,dp[j]);
                curr[j] = ans;
            }
            swap(dp,curr);
        }
        return dp[0];
    }
};