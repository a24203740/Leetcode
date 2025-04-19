#include "../includes.hpp"

struct fenwickTree {
  // https://cp-algorithms.com/data_structures/fenwick.html
  vector<int> tree;
  int n;

  void init(int _n) {
    this->n = _n;
    tree.assign(_n, 0);
  }
  void init(const vector<int> &v) {
    n = v.size();
    tree.assign(n, 0);
    for (int i = 0; i < n; i++) {
      add(i, v[i]);
    }
  }

  fenwickTree(int _n) : n(_n) { this->init(_n); }
  fenwickTree(const vector<int> &v) { this->init(v); }
  // remove trailing 1s, get left bound of each range
  inline int g(int j) { return j & (j + 1); }
  // flip last 0, get right bound of each range
  inline int h(int j) { return j | (j + 1); }
  int getPrefixSum(int i) {
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
    if (l == 0) {
      return getPrefixSum(r);
    }
    return getPrefixSum(r) - getPrefixSum(l - 1);
  }
  void add(int pos, int val) {
    int j = pos;
    while (j < n) {
      // we know j >= pos, because h(j) only increases j
      // we know g(h(j)) < pos, as h(j) increases j by flipping the last 0
      //  which will must be then flipped back by g(h(j)), probably along with
      //  other 1 bit
      tree[j] += val;
      j = h(j);
    }
  }
};
