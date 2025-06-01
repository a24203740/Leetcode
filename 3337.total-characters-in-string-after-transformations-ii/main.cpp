#include "../includes.hpp"

const int mod = 1e9 + 7;
constexpr int N = 26;
typedef array<array<long long, N>, N> matrix_t;
typedef array<long long, N> state_t;
matrix_t&& operator*(const matrix_t &a, const matrix_t &b) {
  static matrix_t c;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      c[i][j] = 0;
      for (int k = 0; k < N; k++) {
        c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % mod ) % mod;
      }
    }
  }
  return std::move(c);
}
state_t&& operator*(const matrix_t &a, const state_t &b) {
  static state_t c;
  for (int i = 0; i < N; i++) {
    c[i] = 0;
    for (int j = 0; j < N; j++) {
      c[i] = (c[i] + (a[i][j] * b[j]) % mod) % mod;
    }
  }
  return std::move(c);
}
matrix_t&& indentical() {
  static matrix_t mat;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      mat[i][j] = (i == j);
    }
  }
  return std::move(mat);
}
class Solution {
public:
  int lengthAfterTransformations(string s, int t, vector<int> &nums) {
    // mat[j] (1*26 vector) * state (26*1 vector) = how many j will appear in next state
    // mat (26*26) * state (26*1) = next state (26*1)
    // mat^t * state = next t state
    matrix_t mat;
    for(int i = 0; i < 26; i++) {
      for(int j = 0; j < 26; j++) {
        mat[i][j] = 0;
      }
    }
    for (int i = 0; i < 26; i++) {
      int j = (i + 1) % 26;
      int count = nums[i];
      while (count--) {
        mat[j][i] = 1;
        j = (j + 1) % 26;
      }
    }
    state_t state;
    state.fill(0);
    for(auto c : s) {
      state[c - 'a']++;
    }
    matrix_t res = indentical();
    for(int i = 0; i < 31; i++) {
      if((1UL << i) > t) {
        break;
      }
      if((1 << i) & t) {
        res = res * mat;
      }
      mat = mat * mat;
    }
    state = res * state;
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      ans = (ans + state[i]) % mod;
    }
    return ans;
  }
};
