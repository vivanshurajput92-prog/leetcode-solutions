/*
 * Problem: Stone Game
 * Problem ID: 909
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 10.7 MB
 * Synced From: LeetCode
 * Date: 2026-08-02
 */

class Solution {
public:
    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1),curr(n,-1);
        for(int i=n-1;i>=0;i--){
            curr[i] = nums[i];
            dp[i] = nums[i];
            for(int j=i+1;j<n;j++){
                int pickRight = nums[j] - curr[j-1];
                int pickLeft = nums[i] - dp[j];
                curr[j] = max(pickLeft,pickRight);
            }
            swap(dp,curr);
        }
        return dp[n-1];
    }
};