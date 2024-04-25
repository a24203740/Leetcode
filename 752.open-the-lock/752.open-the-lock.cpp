/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
class Solution {
public:
    const int state = 10000;
    vector<int> fliped;
    const int FLIPED = 1;
    const int DEAD = 2;
    array<int, 8> flip(int cur)
    {
        int thousand = cur / 1000;
        int hundred = (cur / 100) % 10;
        int ten = (cur / 10) % 10;
        int one = cur % 10;
        array<int, 8> state;
        state[0] = (thousand == 9? cur - 9000 : cur + 1000);
        state[1] = (thousand == 0? cur + 9000 : cur - 1000);
        state[2] = (hundred == 9? cur - 900 : cur + 100);
        state[3] = (hundred == 0? cur + 900 : cur - 100);
        state[4] = (ten == 9? cur - 90 : cur + 10);
        state[5] = (ten == 0? cur + 90 : cur - 10);
        state[6] = (one == 9? cur - 9 : cur + 1);
        state[7] = (one == 0? cur + 9 : cur - 1);
        return state;
    }
    int openLock(vector<string>& deadends, string target) 
    {
        int targetNum = stoi(target);
        if(targetNum == 0)return 0;
        fliped.resize(state);
        for(auto &s : deadends)
        {
            fliped[stoi(s, nullptr, 10)] = DEAD;
        }
        if(fliped[0] == DEAD)return -1;
        queue<int> q;
        q.push(0);
        fliped[0] = FLIPED;
        int steps = 1;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                int cur = q.front();
                q.pop();
                array<int, 8> adjState = flip(cur);
                for(int i = 0; i < 8; i++)
                {
                    if(fliped[adjState[i]] == 0)
                    {
                        if(adjState[i] == targetNum)
                        {
                            return steps;
                        }
                        fliped[adjState[i]] = FLIPED;
                        q.push(adjState[i]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
// @lc code=end

