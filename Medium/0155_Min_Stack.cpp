/*
 * Problem: Min Stack
 * Problem ID: 155
 * Difficulty: Medium
 * Language: C++
 * Runtime: 71 ms
 * Memory: 151.2 MB
 * Synced From: LeetCode
 * Date: 2026-08-02
 */

class MinStack {
public:
    stack<int> s;
    stack<int> s_min;
    MinStack() {}
    
    void push(int value) {
        if(s_min.empty()) s_min.push(value);
        else if(value <= s_min.top()) s_min.push(value);
        s.push(value);
    }
    
    void pop() {
        if(s.top() == s_min.top()) s_min.pop();
        if(!s.empty()) s.pop();
    }
    
    int top() {
        if(!s.empty()) return s.top();
        else return -1;
    }
    
    int getMin() {
        return s_min.top();
    }
};