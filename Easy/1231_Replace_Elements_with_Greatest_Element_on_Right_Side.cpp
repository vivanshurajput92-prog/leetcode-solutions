/*
 * Problem: Replace Elements with Greatest Element on Right Side
 * Problem ID: 1231
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 72.7 MB
 * Synced From: LeetCode
 * Date: 2026-08-04
 */

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxi = arr[n-1];
        arr[n-1] = -1;
        for(int i=n-2;i>=0;i--){
            int val = arr[i];
            arr[i] = maxi;
            maxi = max(maxi,val);
        }
        return arr;
    }
};