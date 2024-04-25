/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
public:
    vector<int> T;
    Solution()
    {
        T.assign(40, -1);
        T[0] = 0;
        T[1] = T[2] = 1;
    }
    int tribonacci(int n) {
        if(T[n] != -1)
        {
            return T[n];
        }
        else
        {
            for(int i = 0; i <= n; i++)
            {
                if(T[i] == -1)
                {
                    T[i] = T[i-1] + T[i-2] + T[i-3];
                }
            }
        }
        return T[n];
    }
};
// @lc code=end

