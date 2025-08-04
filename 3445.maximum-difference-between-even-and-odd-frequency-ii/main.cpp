#include "../includes.hpp"

class Solution {
public:
  int twoDigit(string s, int k, char a, char b) {
    // cout << "==============================\na: " << a << " b: " << b << endl;
    // cout << "==============================\n";
    // R = reverse = odd, P = passthrough = even
    // value: -a + b
    // if a is odd and b is even, then we want aPbP (maintain a is odd and b is
    // even) so we want minimun of aPbP value, since it can makesure a - b is
    // maximized
    //
    // a odd b even : maximum aPbP
    // a even b odd : maximum aRbR
    // a odd b odd  : maximum aPbR
    // a even b even: maximum aRbP
    int aPbP, aRbR, aPbR, aRbP;
    int n = s.size();
    int left = 0;
    vector<array<int, 4>> bestInPrefix(n + 1, {int(-1e8),int(-1e8),int(-1e8),int(-1e8)});
    vector<pair<int,int>> abPrefixSum(n+1, {0, 0});
    aPbP = aRbR = aPbR = aRbP = -1e8;
    int aCount = 0, bCount = 0;
    int ans = -1e8;
    for (int i = 0; i < n; i++) {
      if (s[i] == a)
        aCount++;
      if (s[i] == b)
        bCount++;
      abPrefixSum[i] = {aCount, bCount};
      if(i - left + 1 > k) {
        auto [aCountLeft, bCountLeft] = abPrefixSum[left];
        while(i - left + 1 > k && aCount - aCountLeft >= 1 && bCount - bCountLeft >= 2) {
          left++; 
          tie(aCountLeft, bCountLeft) = abPrefixSum[left];
        }
      }
      bool aR = aCount % 2 == 1;
      bool bR = bCount % 2 == 1;
      if (i >= k - 1 && aCount >= 1 && bCount >= 2) {
        if (aR && !bR)
          ans = max(ans, aCount - bCount);
      }
      int val = bCount - aCount;
      if (aR && bR) {
        aRbR = max(aRbR, val);
      } else if (aR && !bR) {
        aRbP = max(aRbP, val);
      } else if (!aR && bR) {
        aPbR = max(aPbR, val);
      } else {
        aPbP = max(aPbP, val);
      }
      bestInPrefix[i] = {aPbP, aRbR, aPbR, aRbP};
      // cout << "i: " << i << " aCount: " << aCount << " bCount: " << bCount
      //      << " aR: " << aR << " bR: " << bR << "\naPbP: " << aPbP
      //      << " aRbR: " << aRbR << " aPbR: " << aPbR << " aRbP: " << aRbP
      //      << endl;
      if (left > 0) {
        auto [_aPbP, _aRbR, _aPbR, _aRbP] = bestInPrefix[left - 1];
        int _val = aCount - bCount;
        if (aR && !bR) {
          // cout << "_val + aPbP: " << _val + _aPbP << endl;
          ans = max(ans, _val + _aPbP);
        } else if (!aR && bR) {
          // cout << "_val + aRbR: " << _val + _aRbR << endl;
          ans = max(ans, _val + _aRbR);
        } else if (aR && bR) {
          // cout << "_val + aPbR: " << _val + _aPbR << endl;
          ans = max(ans, _val + _aPbR);
        } else if (!aR && !bR) {
          // cout << "_val + aRbP: " << _val + _aRbP << endl;
          ans = max(ans, _val + _aRbP);
        }
      }
    }
    return ans;
  }
  int maxDifference(string s, int k) {
    int ans = -1e8;
    for (int i = 0; i <= 4; i++) {
      for (int j = 0; j <= 4; j++) {
        if (i == j)
          continue;
        ans = max(ans, twoDigit(s, k, '0' + i, '0' + j));
        // cout << "ans: " << ans << endl;
      }
    }
    return ans;
  }
};
