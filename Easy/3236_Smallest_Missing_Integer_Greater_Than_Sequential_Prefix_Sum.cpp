/*
 * Problem: Smallest Missing Integer Greater Than Sequential Prefix Sum
 * Problem ID: 3236
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 22.7 MB
 * Synced From: LeetCode
 * Date: 2026-08-11
 */

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0] + 1;
        int sum = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1] + 1) sum += nums[i];
            else break;
        }
        vector<bool> a(1500,false);
        for(auto &num : nums){
            a[num] = true;
        }
        for(int i=sum;;i++){
            if(a[i] == false) return i;
        }
        return -1;
    }
};