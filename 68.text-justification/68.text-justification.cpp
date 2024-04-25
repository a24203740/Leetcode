/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int startIdx = 0;
        int count = 0;
        int n = words.size();
        int curWidth = 0;
        vector<string> list;
        for(int i = 0; i < n; i++)
        {
            bool fillLine = false, fillLastLine = false;
            if(curWidth + count + words[i].size() <= maxWidth)
            {
                count++;
                curWidth += words[i].size();
            }
            else fillLine = true;
            if(startIdx + count == n)fillLastLine = true;


            if(fillLastLine)
            {
                string ans;
                for(int i = startIdx; i < startIdx + count; i++)
                {
                    ans += words[i];
                    if(i != startIdx + count - 1)
                    {
                        ans += " ";
                    }
                }
                while(ans.size() < maxWidth)ans += " ";
                list.push_back(ans);
                startIdx = n;
            }
            else if(fillLine)
            {
                string ans;
                int spaceCount = count - 1;
                int totalSpaceSize = maxWidth - curWidth;
                int eachSpaceSize;
                int spaceNeedToPlus1;
                if(spaceCount == 0)
                {
                    eachSpaceSize = 0;
                    spaceNeedToPlus1 = 0;    
                }
                else
                {
                    eachSpaceSize = totalSpaceSize / spaceCount;
                    spaceNeedToPlus1 = totalSpaceSize % spaceCount;
                }
                string space(eachSpaceSize, ' ');
                for(int i = startIdx; i < startIdx + count; i++)
                {
                    ans += words[i];
                    if(i != startIdx + count - 1)
                    {
                        ans += space; 
                        if(spaceNeedToPlus1 > 0)
                        {
                            spaceNeedToPlus1--;
                            ans += " ";
                        }
                    }
                }
                while(ans.size() < maxWidth)ans += " ";
                list.push_back(ans);
                startIdx = i;
                count = 1;
                curWidth = words[i].size();
            }
        }
        if(startIdx < n)
        {
            string ans;
            for(int i = startIdx; i < startIdx + count; i++)
            {
                ans += words[i];
                if(i != startIdx + count - 1)
                {
                    ans += " ";
                }
            }
            while(ans.size() < maxWidth)ans += " ";
            list.push_back(ans);            
        }
        return list;
    }
};
// @lc code=end

