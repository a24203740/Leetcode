/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start


class Solution {
public:
    vector<int> Next;
    void calculateNext(string needle)
    {
        size_t stringSize = needle.size();
        Next.resize(stringSize+1);
        Next[0] = -1;

        int indexSuffix = 0;
        int indexPrefix = -1;

        while(indexSuffix < stringSize)
        {
            if(indexPrefix < 0 || needle[indexSuffix] == needle[indexPrefix])
            {
                Next[indexSuffix + 1] = indexPrefix + 1;
                indexPrefix++;
                indexSuffix++;
            }
            else
            {
                indexPrefix = Next[indexPrefix];
            }

        }
    }   
    int strStr(string haystack, string needle) {
        calculateNext(needle);
        int mainIndex = 0, mainSize = haystack.size();
        int subIndex = 0, subSize = needle.size();
        while(mainIndex < mainSize && subIndex < subSize)
        {
            if(subIndex < 0 || haystack[mainIndex] == needle[subIndex])
            {
                mainIndex++;
                subIndex++;
            }
            else
            {
                subIndex = Next[subIndex];
            }
        }
        if(subIndex == subSize)
        {
            return mainIndex - subSize;
        }
        return -1;
    }
};

// @lc code=end

