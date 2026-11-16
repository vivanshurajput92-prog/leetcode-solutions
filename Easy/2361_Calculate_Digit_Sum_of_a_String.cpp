/*
 * Problem: Calculate Digit Sum of a String
 * Problem ID: 2361
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.8 MB
 * Synced From: LeetCode
 * Date: 2026-11-16
 */

class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string temp = "";
            int ct = 0;
            int sum = 0;
            for(int i=0;i<s.size();i++){
                if(ct == k){
                    temp += to_string(sum);
                    sum = (s[i] - '0');
                    ct = 1;
                }
                else{
                    ct++;
                    sum += (s[i] - '0');
                }
            }
            temp += to_string(sum);
            s = temp;
        }
        return s;
    }
};