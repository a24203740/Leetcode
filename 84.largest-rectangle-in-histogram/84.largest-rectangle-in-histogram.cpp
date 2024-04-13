/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
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
    struct item{
        int height;
        int length;
        item(): height(0), length(0){}
        item(int h, int l): height(h), length(l){}
    };
    int largestRectangleArea(vector<int>& heights) {
        vector<item> monoIncStack;
        int n = heights.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int adjLength = 0;
            while(!monoIncStack.empty() && monoIncStack.back().height >= heights[i])
            {
                adjLength += monoIncStack.back().length;
                ans = max(ans, monoIncStack.back().height * adjLength);
                monoIncStack.pop_back();
            }
            if(heights[i] == 0)continue;
            monoIncStack.push_back(item(heights[i], adjLength+1));
        }
        int adjLength = 0;
        while(!monoIncStack.empty())
        {
            adjLength += monoIncStack.back().length;
            ans = max(ans, monoIncStack.back().height * adjLength);
            monoIncStack.pop_back();
        }
        return ans;
    }
};
// @lc code=end

