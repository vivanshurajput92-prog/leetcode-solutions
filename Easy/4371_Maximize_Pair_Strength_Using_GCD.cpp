/*
 * Problem: Maximize Pair Strength Using GCD
 * Problem ID: 4371
 * Difficulty: Easy
 * Language: C++
 * Runtime: 879 ms
 * Memory: 37 MB
 * Synced From: LeetCode
 * Date: 2026-08-02
 */

class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long power = 1LL * nums[i] * nums[j];
                power /=  pow(__gcd(nums[i],nums[j]),2);
                ans = max(ans,power);
            }
        }
        return ans;
    }
};