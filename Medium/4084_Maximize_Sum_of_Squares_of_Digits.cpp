/*
 * Problem: Maximize Sum of Squares of Digits
 * Problem ID: 4084
 * Difficulty: Medium
 * Language: C++
 * Runtime: 68 ms
 * Memory: 62 MB
 * Synced From: LeetCode
 * Date: 2026-10-14
 */

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num * 9 < sum) return "";
        string ans = "";
        while(num--){
            if(sum >= 9){
                ans.push_back('9');
                sum -= 9;
            }
            else{
                ans.push_back(('0' + sum));
                sum = 0;
            }
        }
        return ans;
    }
};