#include "../includes.hpp"
#include <bitset>

class Solution {
public:
  bool divideArray(vector<int> &nums) {
    bitset<501> table;
    for (auto x : nums) {
      table.flip(x);
    }
    return table.count() == 0;
  }
};

