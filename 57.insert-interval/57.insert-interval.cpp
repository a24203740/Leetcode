/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    inline bool checkOverlap(int nl, int nr, int ol, int orR)
    {
        return (nl <= ol && nr >= ol) ||
                (nl <= orR && nr >= orR) ||
                (nl <= ol && nr >= orR) ||
                (nl >= ol && nr <= orR);
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto eraseL = intervals.end(), eraseR = intervals.end();
        int n = intervals.size();
        for(int i = 0; i < n; i++)
        {
            if(checkOverlap(newInterval[0], newInterval[1], intervals[i][0], intervals[i][1]))
            {
                if(eraseL == intervals.end())
                {
                    eraseL = eraseR = intervals.begin() + i;
                }
                else 
                {
                    eraseR = intervals.begin() + i;
                }
            }
            else if(eraseL != intervals.end())break;
        }
        if(eraseL != intervals.end())
        {
            newInterval[0] = min(newInterval[0], eraseL->at(0));
            newInterval[1] = max(newInterval[1], eraseR->at(1));
            intervals.erase(eraseL, eraseR+1);
        }   
        n = intervals.size();
        int insertLoc = -1;
        for(int i = 0; i < n; i++)
        {
            if(intervals[i][0] > newInterval[0])
            {
                insertLoc = i;
                break;
            }
        }
        if(insertLoc == -1)insertLoc = n;
        intervals.insert(intervals.begin() + insertLoc, newInterval);
        return intervals;
    }
};
// @lc code=end

