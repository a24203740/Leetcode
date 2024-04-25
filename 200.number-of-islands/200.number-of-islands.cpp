/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    const int dr[4]= {1, 0, -1, 0};
    const int dc[4]= {0, 1, 0, -1};
    void DFS(vector<vector<char>>& grid, int r, int c, int R, int C)
    {
        grid[r][c] = 2;
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C || grid[nr][nc] != '1')
            {
                continue;
            }
            DFS(grid, nr, nc, R, C);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int count = 0;
        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++)
            {
                if(grid[r][c] == '1')
                {
                    DFS(grid, r, c, R, C);
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end

