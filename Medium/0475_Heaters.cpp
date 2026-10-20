/*
 * Problem: Heaters
 * Problem ID: 475
 * Difficulty: Medium
 * Language: C++
 * Runtime: 26 ms
 * Memory: 29.2 MB
 * Synced From: LeetCode
 * Date: 2026-10-20
 */

class Solution {
private:
    bool pred(int r,vector<int> &heaters,vector<int> &houses){
        int j = 0;
        for(int i=0;i<houses.size();i++){
            while (j < heaters.size() && heaters[j] + r < houses[i]) {
                j++;
            }
            if (j == heaters.size() || heaters[j] - r > houses[i]) {
                return false;
            }
        }
        return true;
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int lo = 0,hi = 1e9;
        while(hi - lo > 1){
            int mid = lo + (hi - lo) / 2;
            if(pred(mid,heaters,houses)) hi = mid;
            else lo = mid + 1;
        }
        if(pred(lo,heaters,houses)) return lo;
        else if(pred(hi,heaters,houses)) return hi;
        return -1;
    }
};