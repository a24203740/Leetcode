/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    const int dr[4] = {0, 1, 0, -1};
    const int dc[4] = {1, 0, -1, 0};
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> ans(n, vector<int>(n, -1));
        int r = 0, c = 0;
        int num = 1;
        int d = 0;
        while(num <= n*n)
        {
            ans[r][c] = num++;
            int nr = r + dr[d], nc = c + dc[d];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n || ans[nr][nc] != -1)
            {
                d = (d+1)%4;
                nr = r + dr[d];
                nc = c + dc[d];
            }
            r = nr; c = nc;
        }
        return ans;
    }
};
// @lc code=end

