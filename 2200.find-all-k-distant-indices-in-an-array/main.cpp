#include "../includes.hpp"

class Solution {
public:
  vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
    int rb = 0;
    int n = nums.size();
    vector<int> ans;
    for(int i = 0; i < n; i++) {
      if(key == nums[i]) {
        int l = max(rb, i - k);
        int r = i + k;
        for(int x = l; x <= r && x < n; x++) {
          ans.push_back(x);
        }
        rb = r + 1;
      }
    }
    return ans;

  }
};
