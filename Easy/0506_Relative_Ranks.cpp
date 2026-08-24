/*
 * Problem: Relative Ranks
 * Problem ID: 506
 * Difficulty: Easy
 * Language: C++
 * Runtime: 3 ms
 * Memory: 17.5 MB
 * Synced From: LeetCode
 * Date: 2026-08-24
 */

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,int> m;
        vector<int> copy = score;
        sort(copy.begin(),copy.end(),greater<int>());
        for(int i=0;i<copy.size();i++){
            m[copy[i]] = i + 1;
        }
        vector<string> res;
        for(int i=0;i<score.size();i++){
            int rank = m[score[i]];
            if(rank == 1) res.push_back("Gold Medal");
            else if(rank == 2) res.push_back("Silver Medal");
            else if(rank == 3) res.push_back("Bronze Medal");
            else res.push_back(to_string(rank));
        }
        return res;
    }
};