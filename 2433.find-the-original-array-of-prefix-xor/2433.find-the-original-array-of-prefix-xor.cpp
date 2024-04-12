/*
 * @lc app=leetcode id=2433 lang=cpp
 *
 * [2433] Find The Original Array of Prefix Xor
 */

#include <vector>
#include <algorithm>
#include <iostream>


// @lc code=start
class Solution {
public: 
    std::vector<int> findArray(std::vector<int>& pref) {
        int n = pref.size();
        int xorSum = 0;
        for(int i = 0; i < n; i++)
        {
            pref[i] ^= xorSum;
            xorSum ^= pref[i];
        }
        return pref;
    }
};
// @lc code=end

