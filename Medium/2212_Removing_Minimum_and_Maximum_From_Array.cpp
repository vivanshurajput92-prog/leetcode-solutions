/*
 * Problem: Removing Minimum and Maximum From Array
 * Problem ID: 2212
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 92.2 MB
 * Synced From: LeetCode
 * Date: 2026-08-30
 */

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minimum = 1e9;
        int maximum = -1e9;
        int min_idx = -1,max_idx = -1;
        for(int i=0;i<n;i++){
            if(nums[i] > maximum){
                maximum = nums[i];
                max_idx = i;
            }
            if(nums[i] < minimum){
                minimum = nums[i];
                min_idx = i;
            }
        }
        int first = max(min_idx+1,max_idx+1);
        int second = max(n-min_idx,n-max_idx);
        int third = min(min_idx+1,max_idx+1) + min(n-min_idx,n-max_idx);
        return min({first,second,third});
    }
};