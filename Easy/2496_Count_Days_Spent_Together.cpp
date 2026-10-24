/*
 * Problem: Count Days Spent Together
 * Problem ID: 2496
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8 MB
 * Synced From: LeetCode
 * Date: 2026-10-24
 */

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob){
        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> pf(13,0);
        for(int i=1;i<=12;i++){
            pf[i] = pf[i-1] + months[i-1];
        }
        vector<int> year(367,0);
        int bob_arrive_day = pf[(10 * (arriveBob[0] - '0') + (arriveBob[1] - '0'))-1] + (10 * (arriveBob[3] - '0') + (arriveBob[4] - '0'));
        int bob_leave_day = pf[(10 * (leaveBob[0] - '0') + (leaveBob[1] - '0'))-1] + (10 * (leaveBob[3] - '0') + (leaveBob[4] - '0'));
        int alice_arrive_day = pf[(10 * (arriveAlice[0] - '0') + (arriveAlice[1] - '0'))-1] + (10 * (arriveAlice[3] - '0') + (arriveAlice[4] - '0'));
        int alice_leave_day = pf[(10 * (leaveAlice[0] - '0') + (leaveAlice[1] - '0'))-1] + (10 * (leaveAlice[3] - '0') + (leaveAlice[4] - '0'));
        year[bob_arrive_day]++;
        year[bob_leave_day+1]--;
        year[alice_arrive_day]++;
        year[alice_leave_day+1]--;
        int curr = 0;
        int ans = 0;
        for(int i=0;i<=366;i++){
            curr += year[i];
            if(curr == 2) ans++;
        }
        return ans;
    }
};
