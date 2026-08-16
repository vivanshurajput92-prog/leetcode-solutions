/*
 * Problem: Stone Game IX
 * Problem ID: 2156
 * Difficulty: Medium
 * Language: C++
 * Runtime: 6 ms
 * Memory: 131.3 MB
 * Synced From: LeetCode
 * Date: 2026-08-16
 */

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> freq(3,0);
        for (auto& s : stones) freq[s % 3]++;
        if(freq[0] % 2 == 0){
            return freq[1] > 0 && freq[2] > 0;
        }
        return abs(freq[1] - freq[2]) > 2;
    }
};