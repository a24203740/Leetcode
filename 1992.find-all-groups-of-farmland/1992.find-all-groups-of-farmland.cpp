/*
 * @lc app=leetcode id=1992 lang=cpp
 *
 * [1992] Find All Groups of Farmland
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int R = land.size();
        int C = land[0].size();
        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++)
            {
                if(land[r][c] == 1)
                {
                    int rit = r;
                    while(rit + 1 < R && land[rit+1][c] == 1)rit++;
                    int cit = c;
                    while(cit + 1 < C && land[rit][cit+1] == 1)cit++;
                    ans.push_back(vector<int>{r, c, rit, cit});
                    for(int x = r; x <= rit; x++)
                    {
                        for(int y = c; y <= cit; y++)
                        {
                            land[x][y] = 2;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

