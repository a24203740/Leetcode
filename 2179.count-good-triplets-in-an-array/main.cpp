#include "../includes.hpp"

using ll = long long;
class Solution {
  struct fenwickTree {
    // https://cp-algorithms.com/data_structures/fenwick.html
    vector<int> tree;
    int n;

    void init(int _n) {
      this->n = _n;
      tree.assign(_n, 0);
    }
    void init(const vector<int>& v) {
      n = v.size();
      tree.assign(n, 0);
      for(int i = 0; i < n; i++) {
        add(i, v[i]);
      }
    }

    fenwickTree(int _n) : n(_n) {
      this->init(_n);
    }
    fenwickTree(const vector<int>& v) {
      this->init(v);
    }
    // remove trailing 1s, get left bound of each range
    inline int g(int j) {
      return j & (j + 1);
    }
    // flip last 0, get right bound of each range
    inline int h(int j) {
      return j | (j + 1);
    }
    int getPrefixSum(int i) {
      if(i == 0)return tree[0];
      if(i < 0) return 0;
      if(i >= n) i = n - 1;
      int j = i;
      int sum = 0;
      while (j >= 0) {
        // tree[j] is the sum of the range [g(j), j]
        sum += tree[j];
        j = g(j) - 1;
      }
      return sum;
    }
    int getRangeSum(int l, int r) {
      if(l > r)return 0;
      if (l == 0) {
        return getPrefixSum(r);
      }
      return getPrefixSum(r) - getPrefixSum(l - 1);
    }
    void add(int pos, int val) {
      int j = pos;
      while(j < n) {
        // we know j >= pos, because h(j) only increases j
        // we know g(h(j)) < pos, as h(j) increases j by flipping the last 0
        //  which will must be then flipped back by g(h(j)), probably along with other 1 bit
        tree[j] += val;
        j = h(j);
      }
    }
  };
public:
  void buildMap(const vector<int>& nums1, const vector<int>& nums2, vector<int>& resMap) {
    map<int, int> addrMap2;
    int n = nums1.size();
    resMap.resize(n);
    for(int i = 0; i < n; i++) {
      addrMap2.emplace(nums2[i], i);
    }
    for(int i = 0; i < n; i++) {
      resMap[i] = addrMap2[nums1[i]];
    }
  }
  long long goodTriplets(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    fenwickTree ft(n);
    // map(i): position of nums1[i] appear in nums2
    // nums1[i] == nums2[map(i)]
    vector<int> addrMap;
    buildMap(nums1, nums2, addrMap);
    vector<ll> pre(n), suf(n);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
      pre[i] = ft.getPrefixSum(addrMap[i] - 1);
      ft.add(addrMap[i], 1);
    }
    ft.init(n);
    for(int i = n - 1; i >= 0; i--) {
      suf[i] = ft.getRangeSum(addrMap[i] + 1, n - 1);
      ft.add(addrMap[i], 1);
    }
    for(int i = 0; i < n; i++) {
      ans += pre[i] * suf[i];
    }
    return ans;
  }
};
