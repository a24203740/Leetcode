#include "../includes.hpp"

using ll = long long;
class Solution {
public:
  long long minSum(vector<int> &nums1, vector<int> &nums2) {
    ll sum1 = 0, sum2 = 0;
    ll zeroCount1 = 0, zeroCount2 = 0;
    for (int i = 0; i < nums1.size(); ++i) {
      if (nums1[i] == 0) {
        zeroCount1++;
      } else {
        sum1 += nums1[i];
      }
    }
    for (int i = 0; i < nums2.size(); ++i) {
      if (nums2[i] == 0) {
        zeroCount2++;
      } else {
        sum2 += nums2[i];
      }
    }
    if(zeroCount1 == 0 && zeroCount2 == 0) {
      if(sum1 == sum2) {
        return sum1;
      } else {
        return -1;
      }
    }
    if(zeroCount1 == 0 && sum1 < sum2 + zeroCount2) {
      return -1;
    }
    if(zeroCount2 == 0 && sum2 < sum1 + zeroCount1) {
      return -1;
    }
    return max(sum1 + zeroCount1, sum2 + zeroCount2);
  }
};
