/*
 * Problem: Rectangle Overlap
 * Problem ID: 866
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 9.9 MB
 * Synced From: LeetCode
 * Date: 2026-09-14
 */

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return rec1[0] < rec2[2] && rec1[2] > rec2[0] && rec1[1] < rec2[3] && rec1[3] > rec2[1];
    }
};