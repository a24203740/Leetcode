#include "../includes.hpp"

class Solution {
public:
  vector<int> pivotArray(vector<int> &nums, int pivot) {
    int n = nums.size();
    vector<int> less, great;
    less.reserve(n);
    great.reserve(n);
    for (auto x : nums) {
      if(x < pivot)less.push_back(x);
      else if(x > pivot) great.push_back(x);
    }
    int ln = less.size();
    int en = n - ln - great.size();
    for(int i = 0; i < ln; i++){
      nums[i] = less[i];
    }
    for(int i = 0; i < en; i++){
      nums[ln + i] = pivot;
    }
    for(int i = 0; i < great.size(); i++){
      nums[ln + en + i] = great[i];
    }
    return nums;
  }
};
