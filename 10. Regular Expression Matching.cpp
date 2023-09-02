#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) 
    {

        // generate next state function from pattern
        vector<vector<pair<int,int>>> nextState;
        nextState = vector<vector<pair<int,int>>>(p.size() + 1, vector<pair<int,int>>());
        int state = 0;
        for (int i = 0; i < p.size(); i++) 
        {
            if(p[i] == '*') 
            {
                continue;
            }
            if (i < p.size() - 1 && p[i+1] == '*') 
            {
                nextState[state].push_back(make_pair(p[i], state));
                nextState[state].push_back(make_pair('-', state+1));
                state++;
            }
            else 
            {
                nextState[state].push_back(make_pair(p[i], state+1));
                state++;
            }
        }
        int finalState = state;
        // output only for const debug is true
        const bool debug = false;
        if (debug) 
        {
            // output nextState function to check
            for (int i = 0; i < nextState.size(); i++) 
            {
                cout << i << ": ";
                for (int j = 0; j < nextState[i].size(); j++) 
                {
                    cout << (char)(nextState[i][j].first) << " " << nextState[i][j].second << " ";
                }
                cout << endl;
            }
            // output finalstate
            cout << "final state: " << finalState << endl;
        }
        // add a visit table indicate whether a state has been visited
        vector<vector<bool>> visit;
        visit = vector<vector<bool>>(p.size() + 1, vector<bool>(s.size() + 1, false));

        // bfs on NFA and string s
        queue<pair<int,int>> q;
        q.push(make_pair(0, 0));
        while (!q.empty()) 
        {
            if(debug)
            {
                // output queue with format curState -- curIteratorOfS
                cout << "queue: ";  
                queue<pair<int,int>> qCopy = q;
                while (!qCopy.empty()) 
                {
                    cout << qCopy.front().first << " -- " << qCopy.front().second << " | ";
                    qCopy.pop();
                }

                cout << endl;

                // output seperate line
                cout << "----------------" << endl;
            }

            int curState = q.front().first;
            int curIteratorOfS = q.front().second;
            q.pop();
            if (curIteratorOfS >= s.size() && curState == finalState) 
            {
                return true;
            }
            if (curIteratorOfS >= s.size() && curState != finalState) 
            {
                for (int i = 0; i < nextState[curState].size(); i++) 
                {
                    if(nextState[curState][i].first == '-') 
                    {
                        q.push(make_pair(nextState[curState][i].second, curIteratorOfS));
                    }
                }
                continue;
            }
            for (int i = 0; i < nextState[curState].size(); i++) 
            {
                if (nextState[curState][i].first == '.') 
                {
                    if(visit[nextState[curState][i].second][curIteratorOfS + 1])
                    {
                        continue;
                    }
                    visit[nextState[curState][i].second][curIteratorOfS + 1] = true;
                    q.push(make_pair(nextState[curState][i].second, curIteratorOfS + 1));
                }
                else if (nextState[curState][i].first == s[curIteratorOfS]) 
                {
                    if (visit[nextState[curState][i].second][curIteratorOfS + 1])
                    {
                        continue;
                    }
                    
                    visit[nextState[curState][i].second][curIteratorOfS + 1] = true;
                    q.push(make_pair(nextState[curState][i].second, curIteratorOfS + 1));
                }
                else if(nextState[curState][i].first == '-') 
                {
                    if(visit[nextState[curState][i].second][curIteratorOfS])
                    {
                        continue;
                    }
                    visit[nextState[curState][i].second][curIteratorOfS] = true;
                    q.push(make_pair(nextState[curState][i].second, curIteratorOfS));
                }
            }
            
        }
        return false;        
    }
};

int main()
{
    // initialize solution
    Solution sol;
    // input string and pattern
    string s, p;
    s = "aaaaaaaaaaaaaaaaaaab";
    p = "a*a*a*a*a*a*a*a*a*a*";
    // output result
    cout << sol.isMatch(s, p) << endl;
}