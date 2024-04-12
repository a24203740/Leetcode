/*
 * @lc app=leetcode id=2104 lang=cpp
 *
 * [2104] Sum of Subarray Ranges
 */

#include <vector>
#include <algorithm>
#include <iostream>

// @lc code=start
class Solution {
public:
    // void print(const std::vector<std::pair<int,int>>& v)
    // {
    //     for(auto x : v)cout << x.first << " - " << x.second << " || " ;
    //     cout << '\n';
    // }
    Solution()
    {
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
    }
    long long subArrayRanges(std::vector<int>& nums) {
        std::vector<std::pair<int,int>> monoMinStack, monoMaxStack;
        int n = nums.size();
        monoMinStack.reserve(n);
        monoMaxStack.reserve(n);
        long long int minAccumalte = 0, maxAccumalte = 0, ans = 0;
        for(int i=0; i < n; i++)
        {
            int next=nums[i];
            int count = 1;
            while (!monoMinStack.empty() && monoMinStack.back().first >= next)
            {
                auto p = monoMinStack.back();
                monoMinStack.pop_back();
                long long int num = p.first, cnt = p.second;
                count += cnt;
                minAccumalte -= cnt * num;
            }
            monoMinStack.push_back(std::make_pair(next, count));
            //print(monoMinStack);
            minAccumalte += next * static_cast<long long>(count);
            count = 1;
            while (!monoMaxStack.empty() && monoMaxStack.back().first <= next)
            {
                auto p = monoMaxStack.back();
                monoMaxStack.pop_back();
                long long int num = p.first, cnt = p.second;
                count += cnt;
                maxAccumalte -= cnt * num;
            }
            monoMaxStack.push_back(std::make_pair(next, count));
            //print(monoMaxStack);
            maxAccumalte += next * static_cast<long long>(count);
            ans += maxAccumalte - minAccumalte;
        }
        return ans;
    }
};
// @lc code=end

