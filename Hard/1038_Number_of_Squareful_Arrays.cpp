/*
 * Problem: Number of Squareful Arrays
 * Problem ID: 1038
 * Difficulty: Hard
 * Language: C++
 * Runtime: 3 ms
 * Memory: 10.1 MB
 * Synced From: LeetCode
 * Date: 2026-10-09
 */

class Solution {
private:
    bool perfectSquare(int val){
        int root = sqrt(val);
        return ((root*root) == val);
    }
    int f(vector<int> &nums,unordered_set<int> &used,int last_ele){
        if(used.size() == nums.size()){
            return 1;
        }
        int ways = 0;
        for(int i=0;i<nums.size();i++){
            if(used.find(i) == used.end()){
                if (i > 0 && nums[i] == nums[i - 1] && used.find(i - 1) == used.end())
                    continue;
                if(last_ele == -1){
                    used.insert(i);
                    ways += f(nums,used,nums[i]);
                    used.erase(i);
                }
                else if(perfectSquare(nums[i] + last_ele)){
                    used.insert(i);
                    ways += f(nums,used,nums[i]); 
                    used.erase(i);
                }
            }
        }
        return ways;
    }
public:
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> used; 
        return f(nums,used,-1);
    }
};