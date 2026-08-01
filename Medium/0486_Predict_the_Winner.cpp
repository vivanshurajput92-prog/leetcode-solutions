/*
 * Problem: Predict the Winner
 * Problem ID: 486
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 9.5 MB
 * Synced From: LeetCode
 * Date: 2026-08-01
 */

class Solution {
/*private:
    int f(int i,int j,vector<int> &nums,auto &dp){
        if(i == j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        int pickLeft = nums[i] - f(i+1,j,nums,dp);
        int pickRight = nums[j] - f(i,j-1,nums,dp);
        return dp[i][j] = max(pickLeft,pickRight);
    }*/
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1),curr(n,-1);
        for(int i=n-1;i>=0;i--){
            dp[i] = nums[i];
            curr[i] = nums[i];
            for(int j=i+1;j<n;j++){
                int pickLeft = nums[i] - dp[j];
                int pickRight = nums[j] - curr[j-1];
                curr[j] = max(pickLeft,pickRight);
            }
            swap(dp,curr);
        }
        return dp[n-1] >= 0;
    }
};