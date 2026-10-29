/*
 * Problem: Largest Number
 * Problem ID: 179
 * Difficulty: Medium
 * Language: C++
 * Runtime: 22 ms
 * Memory: 15 MB
 * Synced From: LeetCode
 * Date: 2026-10-29
 */

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        bool all_zero = true;
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                all_zero = false;
                break;
            }
        }
        if(all_zero) return "0";
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string first = to_string(nums[i]);
                string second = to_string(nums[j]);
                if (first + second < second + first) {
                    swap(nums[i], nums[j]);
                }
            }
        }
        string ans = "";
        for(int i=0;i<n;i++){
            ans += to_string(nums[i]);
        }
        return ans;
    }
};