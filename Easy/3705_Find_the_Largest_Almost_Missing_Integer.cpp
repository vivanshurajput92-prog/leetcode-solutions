/*
 * Problem: Find the Largest Almost Missing Integer
 * Problem ID: 3705
 * Difficulty: Easy
 * Language: C++
 * Runtime: 2 ms
 * Memory: 29.3 MB
 * Synced From: LeetCode
 * Date: 2026-08-18
 */

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(51,0);
        vector<int> ct(51,0);
        for(int i=0;i<k;i++){
            freq[nums[i]]++;
        }
        for(int i=0;i<51;i++){
            if(freq[i] > 0) ct[i]++;
        }
        int i = 0,j = k-1;
        while(j < n-1){
            freq[nums[i]]--;
            j++;i++;
            freq[nums[j]]++;
            for(int k=0;k<51;k++){
                if(freq[k] > 0) ct[k]++;
            }
        }
        int ans = -1;
        for(int i=0;i<51;i++){
            if(ct[i] == 1) ans = i;
        }
        return ans;
    }
};