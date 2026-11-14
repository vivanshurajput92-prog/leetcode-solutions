/*
 * Problem: Minimum Positive Sum Subarray 
 * Problem ID: 3644
 * Difficulty: Easy
 * Language: C++
 * Runtime: 1 ms
 * Memory: 29.5 MB
 * Synced From: LeetCode
 * Date: 2026-11-14
 */

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = 1e9;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                if(j-i+1 >= l && j-i+1 <= r && sum > 0) ans = min(ans,sum);
            }
        }
        return ans != 1e9 ? ans : -1;
    }
};