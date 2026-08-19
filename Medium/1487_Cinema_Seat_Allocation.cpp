/*
 * Problem: Cinema Seat Allocation
 * Problem ID: 1487
 * Difficulty: Medium
 * Language: C++
 * Runtime: 103 ms
 * Memory: 92.1 MB
 * Synced From: LeetCode
 * Date: 2026-08-19
 */

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> m;
        for(auto &seat : reservedSeats){
            m[seat[0]-1].insert(seat[1]-1); 
        }
        int ct = (n - m.size()) * 2;
        for(auto const& [row, reserved] : m) {
            bool left = true, right = true, middle = true;
            if(reserved.count(1) || reserved.count(2) || reserved.count(3) || reserved.count(4)) left = false;
            if(reserved.count(5) || reserved.count(6) || reserved.count(7) || reserved.count(8)) right = false;
            if(reserved.count(3) || reserved.count(4) || reserved.count(5) || reserved.count(6)) middle = false;
            if(left && right) {
                ct += 2;
            } else if (left || right || middle) {
                ct += 1;
            }
        }
        
        return ct;
    }
};