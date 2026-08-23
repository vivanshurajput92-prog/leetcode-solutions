/*
 * Problem: Sum Game
 * Problem ID: 2039
 * Difficulty: Medium
 * Language: C++
 * Runtime: 7 ms
 * Memory: 13.9 MB
 * Synced From: LeetCode
 * Date: 2026-08-23
 */

class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sum1 = 0, sum2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                cnt1++;
            } else {
                sum1 += num[i] - '0';
            }
        }
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                cnt2++;
            } else {
                sum2 += num[i] - '0';
            }
        }
        if ((cnt1 + cnt2) % 2 != 0) {
            return true;
        }
        if ((sum1 - sum2) * 2 + (cnt1 - cnt2) * 9 == 0) {
            return false;
        }
        return true;
    }
};