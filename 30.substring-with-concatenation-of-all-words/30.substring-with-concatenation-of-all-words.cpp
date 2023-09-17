/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <regex>

using namespace std;



// @lc code=start

class Solution {
public:
    void ZAlgo(const string& S, vector<int>& Z) {
        Z[0] = 0;
        int L = 0;
        int N = S.size();
        for(int i = 1; i < N; i++) {
            int R = L + Z[L]; // [L, R] is the known interval, which is identical to [0, R-L]
            if(R < i) Z[i] = 0; // i has cross the known interval
            else // i reside in known interval
            {
                if(Z[i-L] + i <= R)
                {
                    Z[i] = Z[i-L];
                }
                else
                {
                    Z[i] = R - i;
                }
            }
            
            while(i+Z[i] < N && S[Z[i]] == S[i+Z[i]]) Z[i]++;
            if(Z[i] + i > R) L = i;
        }
    }

    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> subStringTable;
        vector<int> setID;
        vector<int> setSize;

        sort(words.begin(), words.end());

        int wordCount = words.size();  
        int strSize = s.size();

        subStringTable.assign(strSize, -1);
        setID.assign(wordCount, -1);
        int totalWordsSize = 0;

        for(int i = 0; i < wordCount; i++)
        {
            totalWordsSize += words[i].size();
        }

        setID[0] = 0;
        setSize.push_back(1);

        for(int i = 1; i < wordCount; i++)
        {
            if(words[i] == words[i-1])
            {
                setID[i] = setID[i-1];
                setSize[setID[i]]++;
            }
            else
            {
                setID[i] = setID[i-1] + 1;
                setSize.push_back(1);
            }
        }
        
        for(int i = 0; i < wordCount; i++)
        {
            if(i == 0 || setID[i] != setID[i-1])
            {
                int wordSize = words[i].size();
                int MergeStringSize = wordSize + strSize + 1;
                string ZAlgoString = words[i] + "$" + s;
                vector<int> Z(MergeStringSize, 0);
                ZAlgo(ZAlgoString, Z);
                for(int it = wordSize + 1; it < MergeStringSize; it++)
                {
                    if(Z[it] == wordSize)
                    {
                        int position = it - wordSize - 1;
                        subStringTable[position] = setID[i];
                    }
                }
            }

        }  

        vector<int> outputAns;
        int singleWordSize = words[0].size();
        for(int startPos = 0; startPos + totalWordsSize - 1 < strSize; startPos++)
        {
            if(subStringTable[startPos] != -1)
            {
                vector<int> tpSetSize = setSize;
                int usedStringCount = 0;
                for(int it = startPos; it < strSize && usedStringCount < wordCount; it += singleWordSize)
                {
                    int currentSetID = subStringTable[it];
                    if(currentSetID != -1 && tpSetSize[currentSetID] > 0)
                    {
                        tpSetSize[currentSetID]--;
                        usedStringCount++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(usedStringCount == wordCount)
                {
                    outputAns.push_back(startPos);
                }
            }
        }
        return outputAns;
    }
};
// @lc code=end

