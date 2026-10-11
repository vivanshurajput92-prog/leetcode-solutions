/*
 * Problem: Sum of Squares of Special Elements 
 * Problem ID: 2844
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 40.1 MB
 * Synced From: LeetCode
 * Date: 2026-10-11
 */

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            if(n % (i+1) == 0) sum += (nums[i] * nums[i]);
        }
        return sum;
    }
};