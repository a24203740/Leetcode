/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution {
public:
    int R, C;
    int count;
    const int dr[4] = {1, 0, -1, 0};
    const int dc[4] = {0, 1, 0, -1};
    void DFS(vector<vector<int>>& grid, int r, int c)
    {
        for(int i = 0; i < 4; i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C || grid[nr][nc] == 0)
            {
                count++;
            }
            else if(grid[nr][nc] == 1)
            {
                grid[nr][nc] = 2;
                DFS(grid, nr, nc);
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        count = 0;

        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++)
            {
                if(grid[r][c] == 1)
                {
                    grid[r][c] = 2;
                    DFS(grid, r, c);
                    return count;
                }
            }
        }
        return 0;
    }
};
// @lc code=end

