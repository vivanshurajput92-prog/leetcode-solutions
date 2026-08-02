/*
 * Problem: All Paths From Source to Target
 * Problem ID: 813
 * Difficulty: Medium
 * Language: C++
 * Runtime: 23 ms
 * Memory: 19.9 MB
 * Synced From: LeetCode
 * Date: 2026-08-02
 */

class Solution {
    vector<vector<int>> ans;
private:
    void f(int i,auto &graph,vector<int> used){
        if(i == graph.size()-1){
            ans.push_back(used);
        }
        for(auto child : graph[i]){
            used.push_back(child);
            f(child,graph,used);
            used.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> used= {0};
        f(0,graph,used);
        return ans;
    }
};