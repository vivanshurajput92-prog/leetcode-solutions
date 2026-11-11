/*
 * Problem: Minimum Cost to Acquire Required Items
 * Problem ID: 4147
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 9.3 MB
 * Synced From: LeetCode
 * Date: 2026-11-11
 */

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans;
        if(cost1 + cost2 < costBoth) ans = 1LL * cost1 * need1 + 1LL * cost2 * need2;
        else{
            long long ans1 = (1LL * costBoth * min(need1,need2)) + (1LL * (max(need1,need2) - min(need1,need2)) * ((need1 > need2) ? cost1 : cost2));
            long long ans2 = 1LL * max(need1,need2) * costBoth;
            ans = min(ans1,ans2);
        }
        return ans;
    }
};