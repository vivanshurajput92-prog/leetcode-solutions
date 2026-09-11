/*
 * Problem: Unique 3-Digit Even Numbers
 * Problem ID: 3799
 * Difficulty: Easy
 * Language: C++
 * Runtime: 3 ms
 * Memory: 30.8 MB
 * Synced From: LeetCode
 * Date: 2026-09-11
 */

class Solution {
public:
    int totalNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i != j && i != k && j != k && nums[i] != 0 && nums[k] % 2 == 0){
                        int num = nums[i] * 100 + nums[j] * 10 + nums[k];
                        s.insert(num);
                    }
                    else continue;
                }
            }
        }
        return s.size();
    }
};