/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int R = g.size(); int C = g[0].size();
        vector<vector<int>> dp(R, vector<int>(C, 0));
        if(g[0][0] == 1)return 0;
        dp[0][0] = 1;
        for(int c = 1; c < C; c++)
        {
            if(g[0][c] == 1)dp[0][c] = 0;
            else dp[0][c]= dp[0][c-1];
        }
        for(int r = 1; r < R; r++)
        {
            if(g[r][0] == 1)dp[r][0] = 0;
            else dp[r][0]= dp[r-1][0];   
        }
        for(int r = 1; r < R; r++)
        {
            for(int c = 1; c < C; c++)
            {
                if(g[r][c] == 1)dp[r][c] = 0;
                else dp[r][c] = dp[r-1][c] + dp[r][c-1];
            }
        }
        return dp[R-1][C-1];
    }
};
// @lc code=end

