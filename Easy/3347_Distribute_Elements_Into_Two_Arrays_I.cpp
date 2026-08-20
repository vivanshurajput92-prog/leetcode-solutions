/*
 * Problem: Distribute Elements Into Two Arrays I
 * Problem ID: 3347
 * Difficulty: Easy
 * Language: C++
 * Runtime: 1 ms
 * Memory: 24 MB
 * Synced From: LeetCode
 * Date: 2026-08-20
 */

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            if(arr1[arr1.size()-1] > arr2[arr2.size()-1]){
                arr1.push_back(nums[i]);
            }
            else arr2.push_back(nums[i]);
        }
        vector<int> res;
        res = arr1;
        res.insert(res.end(),arr2.begin(),arr2.end());
        return res;
    }
};