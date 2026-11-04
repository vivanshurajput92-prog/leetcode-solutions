/*
 * Problem: Minimum Operations to Make Elements Within K Subarrays Equal
 * Problem ID: 3717
 * Difficulty: Hard
 * Language: C++
 * Runtime: 1395 ms
 * Memory: 446.5 MB
 * Synced From: LeetCode
 * Date: 2026-11-04
 */

class Solution {
public:
    multiset<long long> L, R;
    long long sum_L = 0, sum_R = 0;
    int left_size;

    void balance() {
        while (L.size() < left_size && !R.empty()) {
            multiset<long long>::iterator it = R.begin();
            long long val = *it;
            sum_R -= val;
            sum_L += val;
            L.insert(val);
            R.erase(it);
        }
        while (L.size() > left_size) {
            multiset<long long>::iterator it = L.end();
            it--;
            long long val = *it;
            sum_L -= val;
            sum_R += val;
            R.insert(val);
            L.erase(it);
        }
    }

    void add(long long val) {
        if (L.empty() || val <= *L.rbegin()) {
            L.insert(val);
            sum_L += val;
        } else {
            R.insert(val);
            sum_R += val;
        }
        balance();
    }

    void remove(long long val) {
        multiset<long long>::iterator it = L.find(val);
        if (it != L.end()) {
            sum_L -= val;
            L.erase(it);
        } else {
            it = R.find(val);
            sum_R -= val;
            R.erase(it);
        }
        balance();
    }

    long long get_cost() {
        long long median = *L.rbegin();
        long long left_cost = (1LL * L.size() * median) - sum_L;
        long long right_cost = sum_R - (1LL * R.size() * median);
        return left_cost + right_cost;
    }

    long long f(int i, int x, int k, vector<long long>& cost, vector<vector<long long>>& dp) {
        if (k == 0) return 0;
        if (i >= cost.size()) return 1e18;
        if (dp[i][k] != -1) return dp[i][k];

        long long take = cost[i] + f(i + x, x, k - 1, cost, dp);
        long long notTake = f(i + 1, x, k, cost, dp);

        return dp[i][k] = min(take, notTake);
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        left_size = (x + 1) / 2;
        L.clear();
        R.clear();
        sum_L = 0;
        sum_R = 0;

        for (int l = 0; l < x; l++) {
            add(nums[l]);
        }

        vector<long long> cost;
        cost.push_back(get_cost());

        int i = 0, j = x - 1;
        while (j < n - 1) {
            remove(nums[i]);
            j++;
            i++;
            add(nums[j]);
            cost.push_back(get_cost());
        }

        int m = cost.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(k + 1, -1));
        return f(0, x, k, cost, dp);
    }
};