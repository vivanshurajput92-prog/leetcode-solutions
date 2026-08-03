/*
 * Problem: Stone Game III
 * Problem ID: 1522
 * Difficulty: Hard
 * Language: C++
 * Runtime: 20 ms
 * Memory: 130.1 MB
 * Synced From: LeetCode
 * Date: 2026-08-03
 */

class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
        int last = 0,second_last = 0,third_last = 0;
        for(int i=n-1;i>=0;i--){
            int take_1 = INT_MIN,take_2 = INT_MIN,take_3 = INT_MIN;
            take_1 = nums[i] - last;
            if(i < n-1) take_2 = nums[i] + nums[i+1] - second_last;
            if(i < n-2) take_3 = nums[i] + nums[i+1] + nums[i+2] - third_last;
            third_last = second_last;
            second_last = last;
            last = max({take_1,take_2,take_3});
        }
        if(last > 0) return "Alice";
        else if(last < 0) return "Bob";
        return "Tie";
    }
};