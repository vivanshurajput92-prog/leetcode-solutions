/*
 * Problem: Implement Stack using Queues
 * Problem ID: 225
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 10.1 MB
 * Synced From: LeetCode
 * Date: 2026-08-02
 */

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            int val = q.front();
            q.pop();
            q.push(val);
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.empty()) return true;
        else return false;
    }
};