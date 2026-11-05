/*
 * Problem: Find the Distance Value Between Two Arrays
 * Problem ID: 1486
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 16.5 MB
 * Synced From: LeetCode
 * Date: 2026-11-05
 */

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            bool flag = false;
            for(int j=0;j<m;j++){
                if(abs(arr1[i]-arr2[j]) <= d){
                    flag = true;
                    break;
                }
            }
            if(!flag) ans++;
        }
        return ans;
    }
};