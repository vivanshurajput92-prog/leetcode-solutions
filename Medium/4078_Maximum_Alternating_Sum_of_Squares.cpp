/*
 * Problem: Maximum Alternating Sum of Squares
 * Problem ID: 4078
 * Difficulty: Medium
 * Language: C++
 * Runtime: 46 ms
 * Memory: 176.1 MB
 * Synced From: LeetCode
 * Date: 2026-10-13
 */

class Solution {
public:
    long long maxAlternatingSum(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            arr[i] = (arr[i] * arr[i]);
        }
        sort(arr.begin(),arr.end());
        long long score = 0;
        for(int i=n-1;i>=0;i--){
            if(i >= (n/2)) score += (1LL * arr[i]); 
            else score -= (1LL * arr[i]);
        }
        return score;
    }
};