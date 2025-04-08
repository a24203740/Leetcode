#include "../includes.hpp"

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    int n = nums.size();
    int maxV = 1;
    int maxIndex = 0;
    vector<int> subsize(n, 1);
    vector<int> prev(n, -1);
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < i; j++) {
        if(nums[i] % nums[j] == 0) {
          if(subsize[j] + 1 > subsize[i]) {
            subsize[i] = subsize[j] + 1;
            prev[i] = j;
          }
        }
        if(subsize[i] > maxV) {
          maxV = subsize[i];
          maxIndex = i;
        }
      }
    }
    vector<int> ans;
    int it = maxIndex;
    while(it != -1) {
      ans.push_back(nums[it]);
      it = prev[it];
    } 
    return ans;
  }
};
