#include "../includes.hpp"

class Solution {
public:
  int countCompleteSubarrays(vector<int> &nums) {
    bitset<3000> s;
    for(auto c: nums) {
      s[c] = 1;
    }
    int totalDistinct = s.count();
    int l, r; l = r = 0;
    int n = nums.size();
    vector<int> cnt(3000, 0);
    int distinct = 0;
    int ans = 0;
    while(r < n) {
      cnt[nums[r]]++;
      if(cnt[nums[r]] == 1) {
        distinct++;
      }
      r++;
      while(l < r && distinct >= totalDistinct) {
        if(cnt[nums[l]] == 1) {
          if(distinct == totalDistinct) {
            break;
          }
          distinct--;
        }
        cnt[nums[l]]--;
        l++;
      }
      if(distinct == totalDistinct) {
        ans += l+1;
      }
    }
    return ans;
  }
};
