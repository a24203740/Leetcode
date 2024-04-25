/*
 * @lc app=leetcode id=2370 lang=cpp
 *
 * [2370] Longest Ideal Subsequence
 */
#include <iostream>
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
    int longestIdealString(string s, int k) {
        vector<int> longestStringEndWith(26, 0);
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int maxLength = 1;
            int curChar = s[i] - 'a';
            for(int c = curChar - k; c <= curChar + k; c++)
            {
                if(c < 0)continue; if(c >= 26)break;
                maxLength = max(maxLength, longestStringEndWith[c] + 1);
            }

            longestStringEndWith[curChar] = max(maxLength, longestStringEndWith[curChar]);
            ans = max(ans, longestStringEndWith[curChar]);
        }
        return ans;
    }
};
// @lc code=end

