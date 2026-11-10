/*
 * Problem: Climbing Stairs II
 * Problem ID: 4041
 * Difficulty: Medium
 * Language: C++
 * Runtime: 21 ms
 * Memory: 177.7 MB
 * Synced From: LeetCode
 * Date: 2026-11-10
 */

class Solution {
public:
    int climbStairs(int n, vector<int>& costs){
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int ans = 1e9;
            for(int jump=1;jump<=3;jump++){
                int j = i + jump;
                int cost = 1e9;
                if(j-1 < n) cost = costs[j-1] + (j-i)*(j-i) + dp[j];
                ans = min(ans,cost);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};