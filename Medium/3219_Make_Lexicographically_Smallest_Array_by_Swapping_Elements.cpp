/*
 * Problem: Make Lexicographically Smallest Array by Swapping Elements
 * Problem ID: 3219
 * Difficulty: Medium
 * Language: C++
 * Runtime: 629 ms
 * Memory: 301.4 MB
 * Synced From: LeetCode
 * Date: 2026-08-29
 */

class dsubysize{
    vector<int> size,par;
public:
    dsubysize(int n){
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            par.push_back(i);
        }
    }
    int findUPar(int u){
        if(par[u] == u) return u;
        return par[u] = findUPar(par[u]);
    }
    void UnionBySize(int u,int v){
        int par_u = findUPar(u);
        int par_v = findUPar(v);
        if(par_v == par_u) return;
        if(size[par_u] > size[par_v]){
            par[par_v] = par_u;
            size[par_u] += size[par_v];
        }
        else{
            par[par_u] = par_v;
            size[par_v] += size[par_u];
        }
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        dsubysize dsu(n);
        vector<pair<int, int>> nums1(n);
        for(int i = 0; i < n; i++){
            nums1[i] = {nums[i], i};
        }
        sort(nums1.begin(), nums1.end());
        for(int i = 1; i < n; i++){
            if(abs(nums1[i].first - nums1[i-1].first) <= limit) {
            dsu.UnionBySize(nums1[i].second, nums1[i-1].second); 
            }
        }
        unordered_set<int> p_ul;
        for(int i=0;i<n;i++){
            p_ul.insert(dsu.findUPar(i));
        }
        unordered_map<int,pair<set<int>,multiset<int>>> v;
        for(int i=0;i<n;i++){
            v[dsu.findUPar(i)].first.insert(i);
            v[dsu.findUPar(i)].second.insert(nums[i]);
        }
        for(int ulp : p_ul){
            auto it = v[ulp].second.begin();
            for(int ind : v[ulp].first){
                nums[ind] = *it;
                it++;
            }
        }
        return nums;
    }
};