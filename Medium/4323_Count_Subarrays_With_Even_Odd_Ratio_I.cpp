/*
 * Problem: Count Subarrays With Even Odd Ratio I
 * Problem ID: 4323
 * Difficulty: Medium
 * Language: C++
 * Runtime: 50 ms
 * Memory: 29.8 MB
 * Synced From: LeetCode
 * Date: 2026-08-02
 */

class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, double a, double b) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            double x = 0,y = 0;
            for(int j=i;j<n;j++){
                if(nums[j] % 2 == 0) x++;
                else y++;
                if(y > 0 && (a/b) >= (x/y)) ans++;
            }
        }
        return ans;
    }
};